#include "mainwindow.h"
#include "ui_window.h"
#include <string>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "rpn.h"
#include <sstream>



void MainWindow::on_RPN_clicked()
{
    QString eq = ui->equation->text();
    if(!eq.isEmpty())
    {
        string var = eq.toLocal8Bit().constData();
        float res = rpn(var);
        eq.setNum(res);
        ui->result->setText(eq);
    }

}


void MainWindow::on_prefix_clicked()
{
    QString eq = ui->equation->text();

    if(!eq.isEmpty())
    {
        string var = eq.toLocal8Bit().constData();
        string result = rpn_to_infix(var);

        ui->result->setText(QString::fromStdString(result ));
    }

}
