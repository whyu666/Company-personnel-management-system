#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "add.h"
#include "output.h"
#include "search.h"
#include "del.h"
#include "save.h"
#include "manager.h"
#include "technician.h"
#include "salesmanager.h"
#include "salesman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_output_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_read_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
