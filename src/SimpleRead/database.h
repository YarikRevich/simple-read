#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

class Database
{
private:
    QSqlDatabase qDatabase;
public:
    static Database* database;

    static Database* instance(){
        if (!Database::database){
            Database::database = new Database();
        }
        return Database::database;
    }

    Database() = default;

    void exec();

    QString getCurrentLanguage();
};

#endif // DATABASE_H
