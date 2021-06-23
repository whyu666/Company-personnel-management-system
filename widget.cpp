#include "widget.h"
#include "ui_widget.h"

QString expression_id, expression_name, expression_grade, expression_salary, expression;
int count_manager = 0, count_technician = 0, count_salesmanager = 0, count_salesman = 0, delete_number = 0;
Manager manager[1000];
Technician technician[1000];
Salesmanager salesmanager[1000];
Salesman salesman[1000];
bool isread = false;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_add_clicked()
{
    add *newadd = new add;
    newadd->show();
}


void Widget::on_pushButton_output_clicked()
{
    output *newoutput = new output;
    newoutput->show();
}


void Widget::on_pushButton_search_clicked()
{
    search *newsearch = new search;
    newsearch->show();
}


void Widget::on_pushButton_delete_clicked()
{
    del *newdelete = new del;
    newdelete->show();
}


void Widget::on_pushButton_save_clicked()
{
    save *newsave = new save;
    newsave->show();
}


void Widget::on_pushButton_read_clicked()
{
    if(isread) {
        QMessageBox::warning(this, "警告", "不能读入");
    }
    else {
        QString filename = QFileDialog::getOpenFileName(this, "选择一个文件", QCoreApplication::applicationFilePath());
        if (filename.isEmpty()) {
            QMessageBox::warning(this, "警告", "请选择一个文件");
        }
        else {
            isread = true;
            int i, length, many = count_manager + count_technician + count_salesmanager + count_salesman;
            if(many != 0) {
                for(int j = 1; j <= many; j++) {
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
                    Person::deletePerson();//读入前，删除程序内保存的对象
                    if(comb[many - j + 1].classname == 1) {
                        manager[comb[many - j + 1].classid].del();
                    }
                    if(comb[many - j + 1].classname == 2) {
                        technician[comb[many - j + 1].classid].del();
                    }
                    if(comb[many - j + 1].classname == 3) {
                        salesmanager[comb[many - j + 1].classid].del();
                    }
                    if(comb[many - j + 1].classname == 4) {
                        salesman[comb[many - j + 1].classid].del();
                    }
                }
            }
            QFile file(filename);//读取
            file.open(QIODevice::ReadOnly);
            QTextStream in(&file);
            QString line;
            i = 0;
            while(!in.atEnd()) {
                i++;
                line += in.readLine();
            }
            length = i;
            QStringList strList = line.split(" ");
            for(i = 0; i < length; i++) {//将读取的信息保存到四大类中
                if(strList[4 * i + 1] == "Manager") {
                    count_manager++;
                    manager[count_manager].set(strList[4 * i + 2], strList[4 * i + 3].toDouble());
                }
                if(strList[4 * i + 1] == "Technician") {
                    count_technician++;
                    technician[count_technician].set(strList[4 * i + 2], strList[4 * i + 3].toDouble(), 1);
                }
                if(strList[4 * i + 1] == "Salesmanager") {
                    count_salesmanager++;
                    salesmanager[count_salesmanager].set(strList[4 * i + 2], strList[4 * i + 3].toDouble(), 100, 0);
                }
                if(strList[4 * i + 1] == "Salesman") {
                    count_salesman++;
                    salesman[count_salesman].set(strList[4 * i + 2], strList[4 * i + 3].toDouble(), 100);
                }
            }
        }
    }
}

