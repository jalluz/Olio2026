#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

void MainWindow::on_countButton_clicked() {

    int count = ui->countEdit->text().toInt();
    count++;
    ui->countEdit->setText(QString::number(count));
    qDebug()<<"Count button clicked"<<count;
}


void MainWindow::on_resetButton_clicked() {
    ui->countEdit->setText("0");
    qDebug()<<"Reset button clicked";
}
