#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include <QString>
#include "person.h"
//#include "manager.h"


class Salesmanager:public Person {
//class Salesmanager:public Manager {
public:
    Salesmanager();
    //Salesmanager(QString newName, double newMoney, double newPercentage, double newSalary);
    //Salesmanager(QString newName, double newMoney, double newPercentage, double newSalary): Manager(newName, newSalary), money(newMoney), percentage(newPercentage) {};
    void set(QString newName, double newMoney, double newPercentage, double newSalary);
    void show() const;
    QString getName();
    int getid();
    void write();
    void out();
    void change();
    void del();
    bool getdel();
    //Salesmanager(Salesmanager &s);
    //friend double calculate(Salesmanager &s1, Salesmanager &s2);
    static double showall();
private:
    int grade = 3;
    QString name;
    double salary;
    //double money, percentage;
    bool isdel = false;
    //Manager m;
    static double all;
};

#endif // SALESMANAGER_H
