#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

class Connection
{
public:
    QSqlDatabase mydb;
    void dbclose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }
    bool clientdbopen()
    {
         mydb=QSqlDatabase::addDatabase("QMYSQL");

        mydb.setHostName("127.0.0.1");      // Connect to the database host name , Here we need to pay attention to （ If it is ”127.0.0.1“, Unable to connect , Is changed to localhost)
        mydb.setPort(3306);                 // Connection database port number , Consistent with settings
        mydb.setDatabaseName("clients");      // Connection database name , Consistent with settings
        mydb.setUserName("root");          // Database user name , Consistent with settings
        mydb.setPassword("root");

        if(mydb.open())
        {
            return true;
        }
        else
        {
            qDebug()<<"Failed to open database";
            return false;
        }
    }
        bool employeedbopen()
        {
            mydb=QSqlDatabase::addDatabase("QMYSQL");

           mydb.setHostName("127.0.0.1");      // Connect to the database host name , Here we need to pay attention to （ If it is ”127.0.0.1“, Unable to connect , Is changed to localhost)
           mydb.setPort(3306);                 // Connection database port number , Consistent with settings
           mydb.setDatabaseName("employee");      // Connection database name , Consistent with settings
           mydb.setUserName("root");          // Database user name , Consistent with settings
           mydb.setPassword("root");

           if(mydb.open())
           {
               return true;
           }
           else
           {
               qDebug()<<"Failed to open database";
               return false;
           }

        }
        bool facilitiesdbopen()
        {
            mydb=QSqlDatabase::addDatabase("QMYSQL");

           mydb.setHostName("127.0.0.1");      // Connect to the database host name , Here we need to pay attention to （ If it is ”127.0.0.1“, Unable to connect , Is changed to localhost)
           mydb.setPort(3306);                 // Connection database port number , Consistent with settings
           mydb.setDatabaseName("facilities");      // Connection database name , Consistent with settings
           mydb.setUserName("root");          // Database user name , Consistent with settings
           mydb.setPassword("root");

           if(mydb.open())
           {
               return true;
           }
           else
           {
               qDebug()<<"Failed to open database";
               return false;
           }
}
};

#endif // CONNECTION_H
