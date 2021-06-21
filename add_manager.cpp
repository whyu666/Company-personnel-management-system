#include "add_manager.h"
#include "ui_add_manager.h"

extern int count_manager;
extern Manager manager[1000];

add_manager::add_manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_manager)
{
    ui->setupUi(this);
}

add_manager::~add_manager()
{
    delete ui;
}

void add_manager::on_pushButton_clicked()
{
    /*try {
        QString name = ui->textEdit_name->toPlainText();
        for(int i = 0; i < name.length(); i++) {
            if(name[i] == 'w' && name[i+1] == 'a') {
                throw name;
            }
        }
    } catch(QString name) {
        QMessageBox::warning(this,"警告","姓名中包含违禁词：" + name);
        exit(1);
    }*/
    QString name = ui->textEdit_name->toPlainText();
    QString salary = ui->textEdit_salary->toPlainText();//读取name和salary
    char temp[1000];
    QByteArray ba = salary.toLocal8Bit();
    memcpy(temp, ba.data(), ba.size() + 1);//将QString转换为Char*
    int i, point_location = -1, length = strlen(temp);
    bool flag = true;
    if(length == 0) {
        flag = false;
    }
    //try {
    for(i = 0;i < length; i++) {
        if(temp[i] < '.' || (temp[i] > '.' && temp[i] < '0') || temp[i] > '9') {//判断非法字符
            flag = false;
            //throw temp;
            break;
        }
        if(temp[i] == '.' && (point_location != -1)) {//判断非法小数点
            flag = false;
            //throw temp;
            break;
        }
        if(temp[i] == '.') {//判断小数点
            if(i == 0 || i == length - 1) {
                flag = false;
                break;
            }
            point_location = i;//记录小数点位置
        }
    }
    /*} catch(char temp[1000]) {
        QString str = QString::fromLocal8Bit(temp, strlen(temp));
        QMessageBox::warning(this, "警告", "您输入有误：" + str);
    }*/
    if(flag) {//计算salary的值，将Char*转换为double
        double newSalary = 0;
        for(i = 0; i < length; i++) {
            if(point_location == -1) {
                newSalary += (temp[i] - '0') * pow(10, length - i - 1);
            }
            else {
                if(i < point_location) {
                    newSalary += (temp[i] - '0') * pow(10, point_location - i - 1);
                }
                if(i > point_location) {
                    newSalary += (temp[i] - '0') * pow(0.1, i - point_location);
                }
            }
        }
        count_manager++;
        manager[count_manager].set(name, newSalary);//新建manager对象
        //+ manager[count_manager];
        ui->textEdit_name->clear();
        ui->textEdit_salary->clear();//清空文本框
    }
    else {
        ui->textEdit_salary->clear();
        QMessageBox::warning(this, "警告", "输入有误，请重新输入");//报错
    }
}

