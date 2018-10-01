#include <QCoreApplication>
#include <QByteArray>
#include <QtDebug>
#include <accessingDb.h>
#include <iostream>
#include <QCommandLineParser>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();
    if(args.count() != 3) {
	std::cerr << "Wrong number of arguments" << std::endl;
	return 1;
    }
    QCommandLineParser parser;
    QCommandLineOption fileInputOption("i", QCoreApplication::translate("main", "Take input text to decode.")); 
    parser.addOption(fileInputOption);
    parser.process(app);
    bool inputOptionGiven = parser.isSet(fileInputOption);
    if(inputOptionGiven) {
        const QString path = argv[2];
        if(!QFile::exists(path) || path.mid(path.length() - 2, 2) != "db") {
	    qDebug() << "Db doesn't exist.";
	    return 0;
	}
        AccessingDb db(path);

        if (db.isOpen()) {
	    db.printInfo();
            qDebug() << "End of the program";
        }
        else
        {
	    qDebug() << "No database is open.";
        }
    }
   return app.exec();
}
