#include "calc.h"
#include "ui_calc.h"
#include <QObject>
#include <QGridLayout>
#include <QtMath>
#include <QStack>
#include <QKeyEvent>

Calc::Calc(QWidget *parent) :
    QDialog(parent)
{
    qApp->setStyleSheet("QDialog { background: rgb(218, 212, 216)}");
    setWindowTitle("Basic Calculator");
    display = new QLineEdit(tr("0"));
    display->setReadOnly(true);
    display->setStyleSheet("QLineEdit { border-style: outset; "
                                       "min-height: 40; }");
    expressionDisplay = new QLineEdit(tr("0"));
    expressionDisplay->setReadOnly(true);
    expressionDisplay->setStyleSheet("QLineEdit { border-style: outset; "
                                                 "background: rgb(218, 212, 216); "
                                                 "min-height: 30; }");
    m_waitingForOperand = true;
    m_waitingForAddOperator = true;
    m_waitingForMulOperator = true;
    m_equalClicked = false;

    for(int i = 0; i < numButtons; i++) {
        numberButtons[i] = createButton(QString::number(i), SLOT(numberClicked()));
    }
    Button *plusButton = createButton(tr("+"), SLOT(operatorClicked()));
    Button *minusButton = createButton(tr("-"), SLOT(operatorClicked()));
    Button *multiplicationButton = createButton(tr("*"), SLOT(operatorClicked()));
    Button *divisionButton = createButton(tr("/"), SLOT(operatorClicked()));
    Button *equalButton = createButton(tr("="), SLOT(equalSignClicked()));
    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *allCancelButton = createButton(tr("AC"), SLOT(cancelButtonClicked()));
    Button *openParenthesisButton = createButton(tr("("), SLOT(parenthesisClicked()));
    Button *closeParenthesisButton = createButton(tr(")"), SLOT(parenthesisClicked()));

    QGridLayout *calcLayout = new QGridLayout;
    calcLayout->addWidget(expressionDisplay, 0, 0, 1, 6);
    calcLayout->addWidget(display, 1, 0, 1, 6);
    calcLayout->addWidget(multiplicationButton, 2, 3);
    calcLayout->addWidget(divisionButton, 3, 3);
    calcLayout->addWidget(minusButton, 4, 3);
    calcLayout->addWidget(plusButton, 5, 3);
    calcLayout->addWidget(equalButton, 5, 2);
    calcLayout->addWidget(pointButton, 5, 1);
    calcLayout->addWidget(openParenthesisButton, 2, 5);
    calcLayout->addWidget(closeParenthesisButton, 3, 5);
    calcLayout->addWidget(allCancelButton, 4, 5, 2, 1);
    calcLayout->addWidget(numberButtons[0], 5, 0);
    for(int i = 1; i < numButtons; i++) {
        int row = (9 - i)/3 + 2;
        int column = (8 + i) % 3;
        calcLayout->addWidget(numberButtons[i], row, column);
    }
    this->setLayout(calcLayout);
}


void Calc::numberClicked() {
    Button *clickedButton = qobject_cast<Button *>(sender());
    m_clickedValue = clickedButton->text().toInt();
    buttonClicked(m_clickedValue);
}


void Calc::buttonClicked(int &m_clickedValue) {
    if(m_waitingForOperand) {
        display->clear();
        m_waitingForOperand = false;
    }

    if(display->text() == "0") {
        display->setText(QString::number(m_clickedValue));
    } else {
        display->setText(display->text() + QString::number(m_clickedValue));
    }

    if(expressionDisplay->text() == "0") {
        expressionDisplay->setText(QString::number(m_clickedValue));
    } else if(m_equalClicked) {
        m_equalClicked = false;
        expressionDisplay->setText(display->text());
    } else {
        expressionDisplay->setText(expressionDisplay->text() + QString::number(m_clickedValue));
    }
    m_waitingForAddOperator = true;
    m_waitingForMulOperator = true;
}


void Calc::pointClicked() {
    if(m_equalClicked || (!m_waitingForAddOperator && !m_waitingForMulOperator)) {
        return;
    }

    if(!display->text().contains(".")) {
        expressionDisplay->setText(expressionDisplay->text() + ".");
        display->setText(display->text() + ".");
    }
}


void Calc::operatorClicked() {
    Button *clickedButton = qobject_cast<Button *>(sender());
    m_clickedOperator = clickedButton->text();
    operatorClickedEvent(m_clickedOperator);
}


void Calc::operatorClickedEvent(QString &m_clickedOperator) {
    if((m_clickedOperator == "*" || m_clickedOperator == "/") && !m_waitingForMulOperator) {
        return;
    }
    if((m_clickedOperator == "+" || m_clickedOperator == "-") && !m_waitingForAddOperator) {
        return;
    }
    containsEqualSign(m_clickedOperator);
    m_waitingForOperand = true;
    m_waitingForAddOperator = false;
    m_waitingForMulOperator = false;
}

void Calc::parenthesisClicked() {
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedParenthesis = clickedButton->text();

    if(display->text() == "0") {
        expressionDisplay->setText(clickedParenthesis);
    } else {
        expressionDisplay->setText(expressionDisplay->text() + clickedParenthesis);
    }
    m_waitingForAddOperator = true;
}


void Calc::equalSignClicked() {
    if(!m_waitingForAddOperator && !m_waitingForMulOperator) {
        return;
    }

    if(m_equalClicked) {
        expressionDisplay->setText(display->text() + "=" + display->text());
        return;
    }
    analysingString();
    m_equalClicked = true;
    m_waitingForOperand = true;
    m_waitingForAddOperator = true;
    m_waitingForMulOperator = true;
    m_analysedExpression.clear();
}


void Calc::analysingString() {
    QString expression = expressionDisplay->text();
    if(expression[0] == '-') {
        expression = "0" + expression;
    }
    for(int i=0; i<expression.length(); i++) {
        if(expression[i].isDigit() || expression[i] == '.') {
            m_analysedExpression.push_back(expression[i]);
        } else if(expression[i] == '(') {
            m_operators.push(expression.at(i));
        } else if(expression[i] == ')') {
            m_analysedExpression.push_back(' ');
            while(m_operators.top() != "(") {
                if(!m_operators.isEmpty())
                m_analysedExpression.push_back(m_operators.pop());
            }
            m_operators.pop();
        } else if(!m_operators.isEmpty() && operationPriority(expression.at(i)) > operationPriority(m_operators.top())) {
            if(expression.at(i - 1) == '(') {
                m_analysedExpression.push_back('0');
                m_analysedExpression.push_back(' ');
                m_operators.push(expression.at(i));
            } else {
                m_analysedExpression.push_back(' ');
                m_operators.push(expression.at(i));
            }
        } else {
            m_analysedExpression.push_back(" ");
            if(!m_operators.isEmpty()) {
                m_analysedExpression.push_back(m_operators.pop());
            }
            m_operators.push(expression.at(i));
        }
    }

    while (!m_operators.isEmpty()) {
        m_analysedExpression.push_back(" ");
        m_analysedExpression.push_back(m_operators.pop());
    }
    calculate();
}


void Calc::calculate() {
    for(int i = 0; i < m_analysedExpression.length(); i++) {
        if(m_analysedExpression[i].isDigit() || m_analysedExpression[i] == '.') {
            m_numbers.push_back(m_analysedExpression[i]);
        } else if (m_analysedExpression[i] == ' ') {
            if(!m_numbers.isEmpty()) {
                m_result.push(m_numbers.toDouble());
                m_numbers.clear();
            }
        } else if (m_analysedExpression[i] == '+') {
            if(!m_result.isEmpty()) {
                m_result.push_back(m_result.pop()+m_result.pop());
            }
        } else if (m_analysedExpression[i] == '-') {
            if(!m_result.isEmpty()) {
                m_result.push_back(-(m_result.pop() - m_result.pop()));
            }
        } else if (m_analysedExpression[i] == '*') {
            if(!m_result.isEmpty()) {
                m_result.push_back(m_result.pop()*m_result.pop());
            }
        } else if (m_analysedExpression[i] == '/') {
            if(!m_result.isEmpty()) {
                if(m_result.top() == 0.0) {
                    cancelButtonClicked();
                    expressionDisplay->setText("Division by zero is not allowed.");
                    return;

                } else
                m_result.push_back(1/m_result.pop()*m_result.pop());
            }
        }
    }

    if(!m_result.isEmpty()) {
        display->setText(QString::number(m_result.pop()));
    }
    expressionDisplay->setText(expressionDisplay->text() + "=" + display->text());
}


int Calc::operationPriority(const QString &Operator) {
    if(Operator == "(") return 0;
    else if (Operator == "+" || Operator == "-") return 1;
    else if (Operator == "*" || Operator == "/") return 2;
    return 0;
}


void Calc::containsEqualSign(QString &clickedOperator) {
    if(m_equalClicked) {
        m_equalClicked = false;
        expressionDisplay->setText(display->text() + clickedOperator);
    } else {
        expressionDisplay->setText(expressionDisplay->text() + clickedOperator);
    }
}

void Calc::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_0:
            m_clickedValue = 0;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_1:
            m_clickedValue = 1;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_2:
            m_clickedValue = 2;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_3:
            m_clickedValue = 3;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_4:
            m_clickedValue = 4;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_5:
            m_clickedValue = 5;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_6:
            m_clickedValue = 6;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_7:
            m_clickedValue = 8;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_8:
            m_clickedValue = 9;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_9:
            m_clickedValue = 10;
            buttonClicked(m_clickedValue);
            break;
        case Qt::Key_Period:
            pointClicked();
            break;
        case Qt::Key_Enter:
            equalSignClicked();
            break;
        case Qt::Key_Plus:
        case Qt::Key_Minus:
        case Qt::Key_Asterisk:
        case Qt::Key_Slash:
            m_clickedOperator = event->text();
            operatorClickedEvent(m_clickedOperator);
            break;
        default:
            event->ignore();
            break;
    }
}

void Calc::cancelButtonClicked() {
    display->setText("0");
    expressionDisplay->setText("0");
    m_waitingForOperand = true;
    m_waitingForAddOperator = true;
    m_waitingForMulOperator = true;
    m_equalClicked = false;
    m_result.clear();
    m_operators.clear();
    m_numbers.clear();
}

Button *Calc::createButton(const QString &text, const char *member) {
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

Calc::~Calc()
{
   //delete ui;
}
