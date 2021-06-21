#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include "add_manager.h"
#include "add_technician.h"
#include "add_salesmanager.h"
#include "add_salesman.h"

namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_pushButton_manager_clicked();

    void on_pushButton_technician_clicked();

    void on_pushButton_salesmanager_clicked();

    void on_pushButton_salesman_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
