#include "SMainWindow.h"
#include "ui_SMainWindow.h"
#include<QMovie>
SMainWindow::SMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SMainWindow)
{
    ui->setupUi(this);
    ui->label->setFixedSize(this->size());
    mv = new QMovie(":/new/res/start.gif");
    mv->setScaledSize(ui->label->size());

     mv->start();
    ui->label->setMovie(mv);

}

SMainWindow::~SMainWindow()
{
    delete mv;
    delete ui;
}
