#include "add_salesmanager.h"
#include "ui_add_salesmanager.h"

extern int count_salesmanager;
extern Salesmanager salesmanager[1000];
extern bool isread;

add_salesmanager::add_salesmanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_salesmanager)
{
    ui->setupUi(this);
}

add_salesmanager::~add_salesmanager()
{
    delete ui;
}

void add_salesmanager::on_pushButton_clicked()
{
    QString name = ui->textEdit_name->toPlainText();
    QString money = ui->textEdit_money->toPlainText();
    QString percentage = ui->textEdit_percentage->toPlainText();
    QString salary = ui->textEdit_salary->toPlainText();
    char temp[1000];
    QByteArray ba = money.toLocal8Bit();
    memcpy(temp, ba.data(), ba.size() + 1);
    int i, point_location = -1, length = strlen(temp);
    bool flaga = true, flagb = true, flagc = true;
    double newmoney = 0, newpercentage = 0, newsalary = 0;
    if(length == 0) {
        flaga = false;
    }
    for(i = 0; i < length; i++) {
        if(temp[i] < '.' || (temp[i] > '.' && temp[i] < '0') || temp[i] > '9') {
            flaga = false;
            break;
        }
        if(temp[i] == '.' && (point_location != -1)) {
            flaga = false;
            break;
        }
        if(temp[i] == '.') {
            if(i == 0 || i == length - 1) {
                flaga = false;
                break;
            }
            point_location = i;
        }
    }
    if(flaga) {
        for(i = 0; i < length; i++) {
            if(point_location == -1) {
                newmoney += (temp[i] - '0') * pow(10, length - i - 1);
            }
            else {
                if(i < point_location) {
                    newmoney += (temp[i] - '0') * pow(10, point_location - i - 1);
                }
                if(i > point_location) {
                    newmoney += (temp[i] - '0') * pow(0.1, i - point_location);
                }
            }
        }
    }
    else {
        ui->textEdit_money->clear();
    }
    ba = percentage.toLocal8Bit();
    memcpy(temp, ba.data(), ba.size() + 1);
    point_location = -1, length = strlen(temp);
    if(length == 0) {
        flagb = false;
    }
    for(i = 0; i < length; i++) {
        if(temp[i] < '.' || (temp[i] > '.' && temp[i] < '0') || temp[i] > '9') {
            flagb = false;
            break;
        }
        if(temp[i] == '.' && (point_location != -1)) {
            flagb = false;
            break;
        }
        if(temp[i] == '.') {
            if(i == 0 || i == length - 1) {
                flagb = false;
                break;
            }
            point_location = i;
        }
    }
    if(flagb) {
        for(i = 0; i < length; i++) {
            if(point_location == -1) {
                newpercentage += (temp[i] - '0') * pow(10, length - i - 1);
            }
            else {
                if(i < point_location) {
                    newpercentage += (temp[i] - '0') * pow(10, point_location - i - 1);
                }
                if(i > point_location) {
                    newpercentage += (temp[i] - '0') * pow(0.1, i - point_location);
                }
            }
        }
    }
    else {
        ui->textEdit_percentage->clear();
    }
    ba = salary.toLocal8Bit();
    memcpy(temp, ba.data(), ba.size() + 1);
    point_location = -1, length = strlen(temp);
    if(length == 0) {
        flagc = false;
    }
    for(i = 0; i < length; i++) {
        if(temp[i] < '.' || (temp[i] > '.' && temp[i] < '0') || temp[i] > '9') {
            flagc = false;
            break;
        }
        if(temp[i] == '.' && (point_location != -1)) {
            flagc = false;
            break;
        }
        if(temp[i] == '.') {
            if(i == 0 || i == length - 1) {
                flagc = false;
                break;
            }
            point_location = i;
        }
    }
    if(flagc) {
        for(i = 0; i < length; i++) {
            if(point_location == -1) {
                newsalary += (temp[i] - '0') * pow(10, length - i - 1);
            }
            else {
                if(i < point_location) {
                    newsalary += (temp[i] - '0') * pow(10, point_location - i - 1);
                }
                if(i > point_location) {
                    newsalary += (temp[i] - '0') * pow(0.1, i - point_location);
                }
            }
        }
    }
    else {
        ui->textEdit_salary->clear();
    }
    if(!flaga || !flagb || !flagc) {
        QMessageBox::warning(this, "警告", "输入有误，请重新输入");
    }
    if(flaga && flagb && flagc) {
        count_salesmanager++;
        salesmanager[count_salesmanager].set(name, newmoney, newpercentage, newsalary);
        ui->textEdit_name->clear();
        ui->textEdit_money->clear();
        ui->textEdit_percentage->clear();
        ui->textEdit_salary->clear();
        isread = true;
    }
}

