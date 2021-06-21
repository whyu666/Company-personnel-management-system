#ifndef ADD_MANAGER_H
#define ADD_MANAGER_H

#include <QWidget>
#include <QMessageBox>
#include "manager.h"


namespace Ui {
class add_manager;
}

class add_manager : public QWidget
{
    Q_OBJECT

public:
    explicit add_manager(QWidget *parent = nullptr);
    ~add_manager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_manager *ui;
};

#endif // ADD_MANAGER_H
