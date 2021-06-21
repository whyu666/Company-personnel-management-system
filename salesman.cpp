#include "salesman.h"

extern QString expression_id, expression_name, expression_grade, expression_salary, expression;

double Salesman::all = 0;

Salesman::Salesman() {

}
void Salesman::set(QString newName, double newMoney, double newPercentage)
{
    Person::newPerson();
    id = Person::showPerson();
    name = newName;
    salary = newMoney * newPercentage / 100;
}

void Salesman::show() {
    expression_id += QString::number(id);
    expression_id += "\n";
    expression_grade += "Salesman";
    expression_grade += "\n";
    expression_name += name;
    expression_name += "\n";
    expression_salary += QString::number(salary);
    expression_salary += "\n";
}

QString Salesman::getName() {
    return name;
}

int Salesman::getid() {
    return id;
}

void Salesman::write() {
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

void Salesman::out() {
    expression += QString::number(id);
    expression += " ";
    expression += "Manager";
    expression += " ";
    expression += name;
    expression += " ";
    expression += QString::number(salary);
    expression += " ";
    expression += "\n";
}

void Salesman::change() {
    id--;
}

void Salesman::del() {
    isdel = true;
    all -= salary;
    return;
}

bool Salesman::getdel() {
    return isdel;
}

double Salesman::showall() {
    return all;
}
