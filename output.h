#ifndef OUTPUT_H
#define OUTPUT_H

#include <QWidget>
#include "manager.h"
#include "technician.h"
#include "salesmanager.h"
#include "salesman.h"
#include "combine.h"

namespace Ui {
class output;
}

class output : public QWidget
{
    Q_OBJECT

public:
    explicit output(QWidget *parent = nullptr);
    ~output();

private slots:
    void on_pushButton_grade_clicked();

    void on_pushButton_name_clicked();

    void on_pushButton_id_clicked();

private:
    Ui::output *ui;
};

#endif // OUTPUT_H
