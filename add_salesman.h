#ifndef ADD_SALESMAN_H
#define ADD_SALESMAN_H

#include <QWidget>
#include <QMessageBox>
#include "salesman.h"

namespace Ui {
class add_salesman;
}

class add_salesman : public QWidget
{
    Q_OBJECT

public:
    explicit add_salesman(QWidget *parent = nullptr);
    ~add_salesman();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_salesman *ui;
};

#endif // ADD_SALESMAN_H
