#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QMessageBox>
#include "manager.h"
#include "technician.h"
#include "salesmanager.h"
#include "salesman.h"
#include "combine.h"

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_pushButton_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
