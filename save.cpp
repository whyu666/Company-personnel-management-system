#include "save.h"
#include "ui_save.h"

extern int count_manager, count_technician, count_salesmanager, count_salesman, delete_number;
extern Manager manager[1000];
extern Technician technician[1000];
extern Salesmanager salesmanager[1000];
extern Salesman salesman[1000];
extern QString expression;

save::save(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::save)
{
    ui->setupUi(this);
}

save::~save()
{
    delete ui;
}

void save::on_pushButton_name_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "请选择一个文件", QCoreApplication::applicationFilePath());
    if (filename.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择保存位置");
    }
    else {
        combine comb_temp, comb[1000];
        int i, j = 0, many = count_manager + count_technician + count_salesmanager + count_salesman;
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
        for(i = 1; i <= many - delete_number; i++) {
            if(comb[i].classname == 1) {
                manager[comb[i].classid].write();
            }
            if(comb[i].classname == 2) {
                technician[comb[i].classid].write();
            }
            if(comb[i].classname == 3) {
                salesmanager[comb[i].classid].write();
            }
            if(comb[i].classname == 4) {
                salesman[comb[i].classid].write();
            }
        }
        QFile file(filename);//保存文件
        file.open(QIODevice::WriteOnly);
        QByteArray ba = expression.toLocal8Bit();
        file.write(ba);
        file.close();
        expression.clear();
    }
}


void save::on_pushButton_id_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "请选择一个文件", QCoreApplication::applicationFilePath());
    if (filename.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择保存位置");
    }
    else {
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
        for(i =1 ; i <= count_salesmanager; i++) {
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
        for(i = 1; i <= many - delete_number; i++) {
            if(comb[i].classname == 1) {
                manager[comb[i].classid].write();
            }
            if(comb[i].classname == 2) {
                technician[comb[i].classid].write();
            }
            if(comb[i].classname == 3) {
                salesmanager[comb[i].classid].write();
            }
            if(comb[i].classname == 4) {
                salesman[comb[i].classid].write();
            }
        }
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        QByteArray ba = expression.toLocal8Bit();
        file.write(ba);
        file.close();
        expression.clear();
    }
}


void save::on_pushButton_grade_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "请选择一个文件", QCoreApplication::applicationFilePath());
    if (filename.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择保存位置");
    }
    else {
        int i;
        for(i = 1; i <= count_manager; i++) {
            if(!manager[i].getdel())
            {
                manager[i].write();
            }
        }
        for(i = 1; i <= count_technician; i++) {
            if(!technician[i].getdel())
            {
                technician[i].write();
            }
        }
        for(i = 1; i <= count_salesmanager; i++) {
            if(!salesmanager[i].getdel()) {
                salesmanager[i].write();
            }
        }
        for(i = 1; i <= count_salesman; i++) {
            if(!salesman[i].getdel()) {
                salesman[i].write();
            }
        }
    }
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QByteArray ba = expression.toLocal8Bit();
    file.write(ba);
    file.close();
    expression.clear();
}


void save::on_pushButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "请选择一个文件", QCoreApplication::applicationFilePath());
    if (filename.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择保存位置");
    }
    else {
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
        for(i = 1; i <= many - delete_number; i++) {
            if(comb[i].classname == 1) {
                manager[comb[i].classid].out();
            }
            if(comb[i].classname == 2) {
                technician[comb[i].classid].out();
            }
            if(comb[i].classname == 3) {
                salesmanager[comb[i].classid].out();
            }
            if(comb[i].classname == 4) {
                salesman[comb[i].classid].out();
            }
        }
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        QByteArray ba = expression.toLocal8Bit();
        file.write(ba);
        file.close();
        expression.clear();
    }
}

