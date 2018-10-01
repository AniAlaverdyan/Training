#include <accessingDb.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

AccessingDb::AccessingDb(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
       // QSqlQuery query(".tables");
    }

}

AccessingDb::~AccessingDb()
{
    if (m_db.isOpen()) {
	m_db.close();
    }
}

bool AccessingDb::isOpen() const {
    return m_db.isOpen();
}

void AccessingDb::printInfo() const
{
    QSqlQuery query;
    query.prepare("SELECT * FROM mytable");
    
    if(!query.exec()) {
	qDebug() << "Couldn't show the info";
    }
    else {
        while(query.next()) {
	    QSqlRecord record = query.record();
	    qDebug().noquote() << "|ID            |" << record.value(0).toString();
            qDebug().noquote() << "|NAME          |" << record.value(1).toString();
	    qDebug().noquote() << "|TOOLCHAINS    |" << record.value(2).toString();
	    qDebug().noquote() << "|FAMILIES      |" << record.value(3).toString() << "\n";

	}
    }
}
