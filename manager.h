#ifndef MANAGER_H
#define MANAGER_H

#include "person.h"
#include <QString>

class Manager:public Person {
public:
    Manager();
    //Manager(QString newName, double newSalary): name(newName), salary(newSalary) {};
    void set(QString newName, double newSalary);
    void show();
    QString getName();
    int getid();
    void write();
    void out();
    void change();
    void del();
    bool getdel();
    //virtual void setname(QString a);
    //void operator+();
    //void operator-();
    static double showall();
private:
    int grade = 1;
    QString name;
    double salary;
    bool isdel = false;
    static double all;
};

#endif // MANAGER_H
