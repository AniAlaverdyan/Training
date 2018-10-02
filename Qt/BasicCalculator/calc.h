#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QToolButton>
#include <QLineEdit>
#include <QDialog>
#include "button.h"
#include <QStack>

namespace Ui {
class Calc;
}

class Calc : public QDialog
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = nullptr);
    ~Calc();

private:
    Ui::Calc *ui;

    QLineEdit *display;
    QLineEdit *expressionDisplay;

    QString m_analysedExpression;
    QString m_numbers;
    QString clickedOperator;

    QStack<double> m_result;
    QStack<QString> m_operators;

    bool m_equalClicked;
    bool m_waitingForOperand;
    bool m_waitingForAddOperator;
    bool m_waitingForMulOperator;

    int clickedValue;

    enum {numButtons = 10};
    Button *numberButtons[numButtons];

private:
    Button *createButton(const QString &text, const char *member);
    void analysingString();
    void calculate();
    void operatorClickedEvent(QString &m_clickedOperator);
    void containsEqualSign(QString &clickedOperator);
    void keyPressEvent(QKeyEvent *event);
    void buttonClicked(int &clickedValue);
    int operationPriority(const QString &Operator);

private slots:
    void numberClicked();
    void operatorClicked();
    void equalSignClicked();
    void pointClicked();
    void cancelButtonClicked();
    void parenthesisClicked();
};

#endif // CALC_H
