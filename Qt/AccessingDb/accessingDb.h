#ifndef ACCESSINGDB_H
#define ACEESSINGDB_H

#include <QSqlDatabase>

class AccessingDb {
    public:
	AccessingDb(const QString& path);
	~AccessingDb();
	
	bool isOpen() const;
        void printInfo() const;
    private:
	QSqlDatabase m_db;
};

#endif
