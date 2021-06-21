#ifndef ADD_TECHNICIAN_H
#define ADD_TECHNICIAN_H

#include <QWidget>
#include <QMessageBox>
#include "technician.h"

namespace Ui {
class add_technician;
}

class add_technician : public QWidget
{
    Q_OBJECT

public:
    explicit add_technician(QWidget *parent = nullptr);
    ~add_technician();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_technician *ui;
};

#endif // ADD_TECHNICIAN_H
