#ifndef DEL_H
#define DEL_H

#include <QWidget>
#include <QMessageBox>
#include "manager.h"
#include "technician.h"
#include "salesmanager.h"
#include "salesman.h"
#include "combine.h"

namespace Ui {
class del;
}

class del : public QWidget
{
    Q_OBJECT

public:
    explicit del(QWidget *parent = nullptr);
    ~del();

private slots:
    void on_pushButton_id_clicked();

    void on_pushButton_name_clicked();

private:
    Ui::del *ui;
};

#endif // DEL_H
