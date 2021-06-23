#include "salesmanager.h"

extern QString expression_id, expression_name, expression_grade, expression_salary, expression;

double Salesmanager::all = 0;

Salesmanager::Salesmanager() {

}

/*Salesmanager::Salesmanager(QString newName, double newMoney, double newPercentage, double newSalary) {
    Person::newPerson();
    id = Person::showPerson();
    name = newName;
    salary = newMoney * newPercentage / 100 + newSalary;
}*/

/*Salesmanager::Salesmanager(QString newName, double newMoney, double newPercentage, double newSalary) {
    m.set(newName,newSalary);
    money = newMoney;
    percentage = newPercentage;
}*/

void Salesmanager::set(QString newName, double newMoney, double newPercentage, double newSalary)
{
    Person::newPerson();
    id = Person::showPerson();
    name = newName;
    salary = newMoney * newPercentage / 100 + newSalary;
    all += salary;
}

void Salesmanager::show() const {
    expression_id += QString::number(id);
    expression_id += "\n";
    expression_grade += "Salesmanager";
    expression_grade += "\n";
    expression_name += name;
    expression_name += "\n";
    expression_salary += QString::number(salary);
    expression_salary += "\n";
}

QString Salesmanager::getName() {
    return name;
}

int Salesmanager::getid() {
    return id;
}

void Salesmanager::write() {
    int i;
    expression += QString::number(id);
    for(i = 1; i <= 20 - (QString::number(id)).length(); i++) {
        expression += " ";
    }
    expression += "Manager";
    for(i = 1; i <= 20 - 7; i++) {
        expression += " ";
    }
    expression += name;
    for(i = 1; i <= 20 - name.length(); i++) {
        expression += " ";
    }
    expression += QString::number(salary);
    for(i = 1; i <= 20 - (QString::number(salary)).length(); i++) {
        expression += " ";
    }
    expression += "\n";
}

void Salesmanager::out() {
    expression += QString::number(id);
    expression += " ";
    expression += "Salesmanager";
    expression += " ";
    expression += name;
    expression += " ";
    expression += QString::number(salary);
    expression += " ";
    expression += "\n";
}

void Salesmanager::change() {
    id--;
}

void Salesmanager::del() {
    isdel = true;
    all -= salary;
    return;
}

bool Salesmanager::getdel() {
    return isdel;
}

/*Salesmanager::Salesmanager(Salesmanager &s) {
    id = s.id;
    grade = s.grade;
    name = s.name;
    salary = s.salary;
}*/

double Salesmanager::showall() {
    return all;
}

/*template <class T>
void swa (T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
}*/

