#include "search.h"
#include "ui_search.h"

extern int count_manager, count_technician, count_salesmanager, count_salesman, delete_number;
extern Manager manager[1000];
extern Technician technician[1000];
extern Salesmanager salesmanager[1000];
extern Salesman salesman[1000];
extern QString expression_id, expression_name, expression_grade, expression_salary;


search::search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_clicked()
{
    QString search = ui->textEdit->toPlainText();
    int i, j = 0, many = count_manager + count_technician + count_salesmanager + count_salesman;
    combine comb[many + 3], comb_temp;
    //try {
    for(i = 1; i <= count_manager; i++) {
        if(!manager[i].getdel()) {
            j++;
            comb[j].classname = 1;
            comb[j].classid = i;
            comb[j].name = manager[i].getName();
        }
    }
    for(i = 1; i <= count_technician; i++) {
        if(!technician[i].getdel()) {
            j++;
            comb[j].classname = 2;
            comb[j].classid = i;
            comb[j].name = technician[i].getName();
        }
    }
    for(i = 1; i <= count_salesmanager; i++) {
        if(!salesmanager[i].getdel()) {
            j++;
            comb[j].classname = 3;
            comb[j].classid = i;
            comb[j].name = salesmanager[i].getName();
        }
    }
    for(i = 1; i <= count_salesman; i++) {
        if(!salesman[i].getdel()) {
            j++;
            comb[j].classname = 4;
            comb[j].classid = i;
            comb[j].name = salesman[i].getName();
        }
    }
    for(i = 1; i < many - delete_number; i++) {
        int k = i;
        for(j = i; j <= many - delete_number; j++) {
            if(comb[j].name < comb[k].name) {
                k = j;
            }
        }
        if(k != i) {
            comb_temp = comb[k];
            comb[k] = comb[i];
            comb[i] = comb_temp;
        }
    }
    bool f = false;
    for(i = 1; i <= many - delete_number; i++) {
        if(comb[i].classname == 1) {
            if(manager[comb[i].classid].getName() == search) {
                manager[comb[i].classid].show();
                f = true;
            }
        }
        if(comb[i].classname == 2) {
            if(technician[comb[i].classid].getName() == search) {
                technician[comb[i].classid].show();
                f = true;
            }
        }
        if(comb[i].classname == 3) {
            if(salesmanager[comb[i].classid].getName() == search) {
                salesmanager[comb[i].classid].show();
                f = true;
            }
        }
        if(comb[i].classname == 4) {
            if(salesman[comb[i].classid].getName() == search) {
                salesman[comb[i].classid].show();
                f = true;
            }
        }
    }
    /*if(!f) {
        throw search;
    }
    } catch(QString s) {
        QMessageBox::warning(this, "警告", "未找到" + s);
    }*/
    if(!f) {
        QMessageBox::information(this, "查找", "未找到");
    }
    else {
        ui->label_id -> setText(expression_id);
        ui->label_grade->setText(expression_grade);
        ui->label_name->setText(expression_name);
        ui->label_salary->setText(expression_salary);
    }
    expression_id.clear();
    expression_grade.clear();
    expression_name.clear();
    expression_salary.clear();
    ui->textEdit->clear();
}
