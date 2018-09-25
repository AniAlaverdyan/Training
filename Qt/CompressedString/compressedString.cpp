#include <QCoreApplication>
#include <QByteArray>
#include <QtDebug>
#include <QCommandLineParser>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();
    if(args.count() != 3) {
	std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    QCommandLineParser parser;
    QCommandLineOption inputOption("i", QCoreApplication::translate("main", "Take input text to decode."));
    parser.addOption(inputOption);
    parser.process(app);
    bool inputOptionGiven = parser.isSet(inputOption);
    if(inputOptionGiven) {
    	QByteArray result = QByteArray::fromBase64(argv[2]);
    	qDebug() << qUncompress(result);
    }
    return app.exec();
}

