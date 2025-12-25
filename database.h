#ifndef DATABASE_H
#define DATABASE_H

#include "qsqlquery.h"
#include <QSqlDatabase>
#include <QSqlError>

class database
{
public:
    database();
    QSqlDatabase db;
    QSqlQuery* query;
};

#endif // DATABASE_H
