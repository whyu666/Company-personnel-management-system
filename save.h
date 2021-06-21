#ifndef SAVE_H
#define SAVE_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "manager.h"
#include "technician.h"
#include "salesmanager.h"
#include "salesman.h"
#include "combine.h"

namespace Ui {
class save;
}

class save : public QWidget
{
    Q_OBJECT

public:
    explicit save(QWidget *parent = nullptr);
    ~save();

private slots:
    void on_pushButton_name_clicked();

    void on_pushButton_id_clicked();

    void on_pushButton_grade_clicked();

    void on_pushButton_clicked();

private:
    Ui::save *ui;
};

#endif // SAVE_H
