#include "add_technician.h"
#include "ui_add_technician.h"

extern int count_technician;
extern Technician technician[1000];

add_technician::add_technician(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_technician)
{
    ui->setupUi(this);
}

add_technician::~add_technician()
{
    delete ui;
}

void add_technician::on_pushButton_clicked()
{
    QString name = ui->textEdit_name->toPlainText();
    QString hours = ui->textEdit_hours->toPlainText();
    QString hoursalary = ui->textEdit_hoursalary->toPlainText();
    char temp[1000];
    QByteArray ba = hours.toLocal8Bit();
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
        ui->textEdit_hours->clear();
    }
    ba = hoursalary.toLocal8Bit();
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
        ui->textEdit_hoursalary->clear();
    }
    if(flaga == false || flagb == false) {
        QMessageBox::warning(this, "警告", "输入有误，请重新输入");
    }
    if(flaga && flagb) {
        count_technician++;
        technician[count_technician].set(name, newhours, newhoursalary);
        ui->textEdit_name->clear();
        ui->textEdit_hours->clear();
        ui->textEdit_hoursalary->clear();
    }
}

