#ifndef SALESMAN_H
#define SALESMAN_H

#include <QString>
#include "person.h"


class Salesman:public Person {
public:
    Salesman();
    void set(QString newName, double newMoney, double newPercentage);
    void show();
    QString getName();
    int getid();
    void write();
    void out();
    void change();
    void del();
    bool getdel();
    static double showall();
private:
    int grade = 4;
    QString name;
    double salary;
    bool isdel = false;
    static double all;
};

#endif // SALESMAN_H
