#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_manager_clicked()
{
    add_manager *manager = new add_manager;
    manager->show();
}


void add::on_pushButton_technician_clicked()
{
    add_technician *technician = new add_technician;
    technician->show();
}


void add::on_pushButton_salesmanager_clicked()
{
    add_salesmanager *salesmanager = new add_salesmanager;
    salesmanager->show();
}


void add::on_pushButton_salesman_clicked()
{
    add_salesman *salesman = new add_salesman;
    salesman->show();
}

