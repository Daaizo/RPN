#include "mainwindow.h"
#include "ui_mainwindow.h"

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
using namespace std;
void MainWindow::on_RPN_clicked()
{
    QString eq = ui->equation->text();
    string var = eq.toLocal8Bit().constData();
    float res = rpn(var);
    eq.setNum(res);
    ui->result->setText(eq);
}

