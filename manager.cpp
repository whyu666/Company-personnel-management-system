#include "manager.h"
#include <iomanip>

extern QString expression_id, expression_name, expression_grade, expression_salary, expression;

double Manager::all = 0;

Manager::Manager() {

}

void Manager::set(QString newName, double newSalary) {
    Person::newPerson();
    id = Person::showPerson();
    name = newName;
    salary = newSalary;
    all +=salary;
}

void Manager::show() {
    expression_id += QString::number(id);
    expression_id += "\n";
    expression_grade += "Manager";
    expression_grade += "\n";
    expression_name += name;
    expression_name += "\n";
    expression_salary += QString::number(salary);
    expression_salary += "\n";
}

QString Manager::getName() {
    return name;
}
int Manager::getid() {
    return id;
}

void Manager::write() {
    int i;
    expression += QString::number(id);
    for(i = 1; i <= 20 - (QString::number(id)).length(); i++) {//设置输出格式
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

void Manager::out() {//无格式输出
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

void Manager::change() {
    id--;
}

void Manager::del() {
    isdel = true;
    all -= salary;
    return;
}

bool Manager::getdel(){
    return isdel;
}

/*void Manager::setname(QString a) {
    name = a;
}*/

/*void Manager::operator+() {
    all += salary;
    return;
}

void Manager::operator-() {
    all -= salary;
    return;
}*/

double Manager::showall() {
    return all;
}
