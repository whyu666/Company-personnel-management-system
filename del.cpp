#include "del.h"
#include "ui_del.h"

extern int count_manager, count_technician, count_salesmanager, count_salesman, delete_number;
extern Manager manager[1000];
extern Technician technician[1000];
extern Salesmanager salesmanager[1000];
extern Salesman salesman[1000];

del::del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::del)
{
    ui->setupUi(this);
}

del::~del()
{
    delete ui;
}

void del::on_pushButton_id_clicked()
{
    int i, many = count_manager + count_technician + count_salesmanager + count_salesman;
    combine comb[many];
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
    QString id = ui->textEdit->toPlainText();
    char temp[1000];
    QByteArray ba = id.toLocal8Bit();
    memcpy(temp, ba.data(), ba.size() + 1);
    bool flag = true;
    int length = strlen(temp), result = 0;
    for(i = 0; i < length; i++) {
        result += int(temp[i] - '0') * pow(10, length - i - 1);
        if((temp[i] < '0') || temp[i] > '9') {
            flag = false;
            break;
        }
    }
    if(!flag || (result <= 0 || result > many - delete_number)) {
        QMessageBox::warning(this, "警告", "输入有误，请重新输入");
    }
    else {
        Person::deletePerson();//删除人员
        if(comb[result].classname == 1) {
            manager[comb[result].classid].del();
        }
        if(comb[result].classname == 2) {
            technician[comb[result].classid].del();
        }
        if(comb[result].classname == 3) {
            salesmanager[comb[result].classid].del();
        }
        if(comb[result].classname == 4) {
            salesman[comb[result].classid].del();
        }
        for(i = result + 1; i <= many; i++)//修改其他人员id
        {
            if(comb[i].classname == 1) {
                manager[comb[i].classid].change();
            }
            if(comb[i].classname == 2) {
                technician[comb[i].classid].change();
            }
            if(comb[i].classname == 3) {
                salesmanager[comb[i].classid].change();
            }
            if(comb[i].classname == 4) {
                salesman[comb[i].classid].change();
            }
        }
        delete_number++;
    }
    ui->textEdit->clear();
}


void del::on_pushButton_name_clicked()
{
        QString search = ui->textEdit->toPlainText();
        int i, j = 0, many = count_manager + count_technician + count_salesmanager + count_salesman;
        combine comb[many + 3], comb_temp;
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
        for(i = 1;i < many - delete_number; i++) {
            int k = i;
            for(j = i;j <= many - delete_number; j++) {
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
        int result;
        for(i = 1; i <= many - delete_number; i++) {
            if(comb[i].classname == 1) {
                if(manager[comb[i].classid].getName() == search) {
                    manager[comb[i].classid].del();
                    f = true;
                    Person::deletePerson();
                    result = manager[comb[i].classid].getid();
                    break;
                }
            }
            if(comb[i].classname == 2) {
                if(technician[comb[i].classid].getName() == search) {
                    technician[comb[i].classid].del();
                    f = true;
                    Person::deletePerson();
                    result = technician[comb[i].classid].getid();
                    break;
                }
            }
            if(comb[i].classname == 3) {
                if(salesmanager[comb[i].classid].getName() == search) {
                    salesmanager[comb[i].classid].del();
                    f = true;
                    Person::deletePerson();
                    result = salesmanager[comb[i].classid].getid();
                    break;
                }
            }
            if(comb[i].classname == 4) {
                if(salesman[comb[i].classid].getName() == search) {
                    salesman[comb[i].classid].del();
                    f = true;
                    Person::deletePerson();
                    result = salesman[comb[i].classid].getid();
                    break;
                }
            }
        }
        if(!f) {
            QMessageBox::information(this, "警告", "未找到");
        }
        else {
            combine combt[many + 3];
            for(i = 1; i <= count_manager; i++) {
                if(!manager[i].getdel()) {
                    combt[manager[i].getid()].classname = 1;
                    combt[manager[i].getid()].classid = i;
                }
            }
            for(i = 1; i <= count_technician; i++) {
                if(!technician[i].getdel()) {
                    combt[technician[i].getid()].classname = 2;
                    combt[technician[i].getid()].classid = i;
                }
            }
            for(i = 1; i <= count_salesmanager; i++) {
                if(!salesmanager[i].getdel()) {
                    combt[salesmanager[i].getid()].classname = 3;
                    combt[salesmanager[i].getid()].classid = i;
                }
            }
            for(i = 1; i <= count_salesman; i++) {
                if(!salesman[i].getdel()) {
                    combt[salesman[i].getid()].classname = 4;
                    combt[salesman[i].getid()].classid = i;
                }
            }
            for(i = result + 1; i <= many; i++)
            {
                if(combt[i].classname == 1) {
                    manager[combt[i].classid].change();
                }
                if(combt[i].classname == 2) {
                    technician[combt[i].classid].change();
                }
                if(combt[i].classname == 3) {
                    salesmanager[combt[i].classid].change();
                }
                if(combt[i].classname == 4) {
                    salesman[combt[i].classid].change();
                }
            }
            delete_number++;
        }
        ui->textEdit->clear();
}

