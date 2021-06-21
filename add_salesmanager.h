#ifndef ADD_SALESMANAGER_H
#define ADD_SALESMANAGER_H

#include <QWidget>
#include <QMessageBox>
#include "salesmanager.h"

namespace Ui {
class add_salesmanager;
}

class add_salesmanager : public QWidget
{
    Q_OBJECT

public:
    explicit add_salesmanager(QWidget *parent = nullptr);
    ~add_salesmanager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_salesmanager *ui;
};

#endif // ADD_SALESMANAGER_H
