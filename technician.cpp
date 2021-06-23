#include "technician.h"

extern QString expression_id, expression_name, expression_grade, expression_salary, expression;

double Technician::all = 0;

Technician::Technician() {
}

void Technician::set(QString newName, double newHours, double newHourSalary) {
    Person::newPerson();
    id = Person::showPerson();
    name = newName;
    salary = newHours * newHourSalary;
    all += salary;
}

void Technician::show() {
    expression_id += QString::number(id);
    expression_id += "\n";
    expression_grade += "Technician";
    expression_grade += "\n";
    expression_name += name;
    expression_name += "\n";
    expression_salary += QString::number(salary);
    expression_salary += "\n";
}

QString Technician::getName() {
    return name;
}

int Technician::getid() {
    return id;
}

void Technician::write() {
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

void Technician::out() {
    expression += QString::number(id);
    expression += " ";
    expression += "Technician";
    expression += " ";
    expression += name;
    expression += " ";
    expression += QString::number(salary);
    expression += " ";
    expression += "\n";
}

void Technician::change() {
    id--;
}

void Technician::del() {
    isdel = true;
    all -= salary;
    return;
}

bool Technician::getdel() {
    return isdel;
}

double Technician::showall() {
    return all;
}
