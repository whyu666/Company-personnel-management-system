#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include <QString>
#include "person.h"


class Technician:public Person {
public:
    Technician();
    void set(QString newName, double newHours, double newHourSalary);
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
    int grade = 2;
    QString name;
    double salary;
    bool isdel = false;
    static double all;
};

#endif // TECHNICIAN_H
