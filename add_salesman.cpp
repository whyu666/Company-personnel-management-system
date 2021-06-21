#include "add_salesman.h"
#include "ui_add_salesman.h"

extern int count_salesman;
extern Salesman salesman[1000];

add_salesman::add_salesman(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_salesman)
{
    ui->setupUi(this);
}

add_salesman::~add_salesman()
{
    delete ui;
}

void add_salesman::on_pushButton_clicked()
{
    QString name = ui->textEdit_name->toPlainText();
    QString money = ui -> textEdit_money->toPlainText();
    QString percentage = ui->textEdit_percentage->toPlainText();
    char temp[1000];
    QByteArray ba = money.toLocal8Bit();
    memcpy(temp, ba.data(), ba.size() + 1);
    int i, point_location = -1, length = strlen(temp);
    bool flaga = true, flagb = true;
    double newhours = 0, newhoursalary = 0;
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
                newhours += (temp[i] - '0') * pow(10, length - i - 1);
            }
            else {
                if(i < point_location) {
                    newhours += (temp[i] - '0') * pow(10, point_location - i - 1);
                }
                if(i > point_location) {
                    newhours += (temp[i] - '0') * pow(0.1, i - point_location);
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
                newhoursalary += (temp[i] - '0') * pow(10, length - i - 1);
            }
            else {
                if(i < point_location) {
                    newhoursalary += (temp[i] - '0') * pow(10, point_location - i - 1);
                }
                if(i > point_location) {
                    newhoursalary += (temp[i] - '0') * pow(0.1, i - point_location);
                }
            }
        }
    }
    else {
        ui->textEdit_percentage->clear();
    }
    if(flaga == false || flagb == false) {
        QMessageBox::warning(this, "警告","输入有误，请重新输入");
    }
    if(flaga && flagb) {
        count_salesman++;
        salesman[count_salesman].set(name, newhours, newhoursalary);
        ui->textEdit_name->clear();
        ui->textEdit_money->clear();
        ui->textEdit_percentage->clear();
    }
}

