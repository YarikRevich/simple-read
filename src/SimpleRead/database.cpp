#include "database.h"

Database *Database::database = NULL;

void Database::exec() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("SimpleRead");
    if (db.open()){
        QSqlQuery query(db);
        query.prepare();
        query.exec();
        db.close();
    } else {
        qFatal("Failed to establish database connection");
    }


//    query.exec();
    qInfo("Database is initialized");
//    QSqlQuery query(this->qDatabase);
//    query.exec("SELECT value FROM KeyValue WHERE key = 'language'");
}

QString Database::getCurrentLanguage(){

//    while (query.next()) {
//            return query.value(0).toString();
//    }
//    qFatal("Couldn't exec a database query to received language which is currently used in the application");
}
