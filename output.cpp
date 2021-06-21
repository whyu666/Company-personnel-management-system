#include "output.h"
#include "ui_output.h"

extern int count_manager, count_technician, count_salesmanager, count_salesman, delete_number;
extern Manager manager[1000];
extern Technician technician[1000];
extern Salesmanager salesmanager[1000];
extern Salesman salesman[1000];
extern QString expression_id, expression_name, expression_grade, expression_salary;

output::output(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::output)
{
    ui->setupUi(this);
}

output::~output()
{
    delete ui;
}

void output::on_pushButton_grade_clicked()
{
    ui->label_id->setAlignment(Qt::AlignLeft);
    ui->label_grade->setAlignment(Qt::AlignLeft);
    ui->label_name->setAlignment(Qt::AlignLeft);
    ui->label_salary->setAlignment(Qt::AlignLeft);//设置位置
    int i;
    ui->label_id->clear();
    ui->label_grade->clear();
    ui->label_name->clear();
    ui->label_salary->clear();
    for(i = 1; i <= count_manager; i++) {
        if(!manager[i].getdel())
        {
            manager[i].show();
        }
    }
    for(i = 1; i <= count_technician; i++) {
        if(!technician[i].getdel())
        {
            technician[i].show();
        }
    }
    for(i = 1; i <= count_salesmanager; i++) {
        if(!salesmanager[i].getdel()) {
            salesmanager[i].show();
        }
    }
    for(i = 1; i <= count_salesman; i++) {
        if(!salesman[i].getdel()) {
            salesman[i].show();
        }
    }
    int many = count_manager + count_technician + count_salesmanager + count_salesman;
    if(many != 0) {//计算总工资
        expression_salary += QString::number(Manager::showall() + Technician::showall() + Salesmanager::showall() + Salesman::showall());
    }
    ui->label_id->setText(expression_id);
    ui->label_grade->setText(expression_grade);
    ui->label_name->setText(expression_name);
    ui->label_salary->setText(expression_salary);//显示
    expression_id.clear();
    expression_grade.clear();
    expression_name.clear();
    expression_salary.clear();
}


void output::on_pushButton_name_clicked()
{
    ui->label_id->setAlignment(Qt::AlignLeft);
    ui->label_grade->setAlignment(Qt::AlignLeft);
    ui->label_name->setAlignment(Qt::AlignLeft);
    ui->label_salary->setAlignment(Qt::AlignLeft);
    ui->label_id->clear();
    ui->label_grade->clear();
    ui->label_name->clear();
    ui->label_salary->clear();
    combine comb_temp, comb[1000];
    int i, j = 0, many = count_manager + count_technician + count_salesmanager + count_salesman;
    for(i = 1; i <= count_manager; i++) {//将四大类转换到comb中
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
    for(i = 1; i < many - delete_number; i++) {//按姓名排序
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
    for(i = 1; i <= many - delete_number; i++) {//排序好后输出
        if(comb[i].classname == 1) {
            manager[comb[i].classid].show();
        }
        if(comb[i].classname == 2) {
            technician[comb[i].classid].show();
        }
        if(comb[i].classname == 3) {
            salesmanager[comb[i].classid].show();
        }
        if(comb[i].classname == 4) {
            salesman[comb[i].classid].show();
        }
    }
    if(many != 0) {
        expression_salary += QString::number(Manager::showall() + Technician::showall() + Salesmanager::showall() + Salesman::showall());
    }
    ui->label_id->setText(expression_id);
    ui->label_grade->setText(expression_grade);
    ui->label_name->setText(expression_name);
    ui->label_salary->setText(expression_salary);
    expression_id.clear();
    expression_grade.clear();
    expression_name.clear();
    expression_salary.clear();
}


void output::on_pushButton_id_clicked()
{
    ui->label_id->setAlignment(Qt::AlignLeft);
    ui->label_grade->setAlignment(Qt::AlignLeft);
    ui->label_name->setAlignment(Qt::AlignLeft);
    ui->label_salary->setAlignment(Qt::AlignLeft);
    ui->label_id->clear();
    ui->label_grade->clear();
    ui->label_name->clear();
    ui->label_salary->clear();
    int i, many = count_manager + count_technician + count_salesmanager + count_salesman;
    combine comb[1000];
    for(i = 1; i <= count_manager; i++) {
        if(!manager[i].getdel()) {
            comb[manager[i].getid()].classname = 1;
            comb[manager[i].getid()].classid = i;
        }
    }
    for(i = 1; i <= count_technician; i++) {
        if(!technician[i].getdel()) {
            comb[technician[i].getid()].classname = 2;
            comb[technician[i].getid()].classid = i;
        }
    }
    for(i = 1; i <= count_salesmanager; i++) {
        if(!salesmanager[i].getdel()) {
            comb[salesmanager[i].getid()].classname = 3;
            comb[salesmanager[i].getid()].classid = i;
        }
    }
    for(i = 1; i <= count_salesman; i++) {
        if(!salesman[i].getdel()) {
            comb[salesman[i].getid()].classname = 4;
            comb[salesman[i].getid()].classid = i;
        }
    }
    for(i = 1;i <= many - delete_number; i++) {
        if(comb[i].classname == 1) {
            manager[comb[i].classid].show();
        }
        if(comb[i].classname == 2) {
            technician[comb[i].classid].show();
        }
        if(comb[i].classname == 3) {
            salesmanager[comb[i].classid].show();
        }
        if(comb[i].classname == 4) {
            salesman[comb[i].classid].show();
        }
    }
    if(many != 0) {
        expression_salary += QString::number(Manager::showall() + Technician::showall() + Salesmanager::showall() + Salesman::showall());
    }
    ui->label_id->setText(expression_id);
    ui->label_grade->setText(expression_grade);
    ui->label_name->setText(expression_name);
    ui->label_salary->setText(expression_salary);
    expression_id.clear();
    expression_grade.clear();
    expression_name.clear();
    expression_salary.clear();
}


