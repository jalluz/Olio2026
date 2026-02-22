#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::numberClickHandler);

    connect(ui->addBtn, &QPushButton::clicked, this, &MainWindow::addHandler);
    connect(ui->subBtn, &QPushButton::clicked, this, &MainWindow::subHandler);
    connect(ui->mulBtn, &QPushButton::clicked, this, &MainWindow::mulHandler);
    connect(ui->divBtn, &QPushButton::clicked, this, &MainWindow::divHandler);

    connect(ui->enterBtn, &QPushButton::clicked, this, &MainWindow::enterHandler);
    connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearHandler);

    number1 = "";
    number2 = "";
    state = 1;
    operand = 0;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn0_clicked()
{

}


void MainWindow::on_btn1_clicked()
{

}


void MainWindow::on_btn2_clicked()
{

}


void MainWindow::on_btn3_clicked()
{

}


void MainWindow::on_btn4_clicked()
{

}


void MainWindow::on_btn5_clicked()
{

}


void MainWindow::on_btn6_clicked()
{

}


void MainWindow::on_btn7_clicked()
{

}


void MainWindow::on_btn8_clicked()
{

}


void MainWindow::on_btn9_clicked()
{

}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(!button) return;

    QString digit = button->text();

    if(state == 1)
    {
        number1 += digit;
        ui->num1Edit->setText(number1);
    }
    else
    {
        number2 += digit;
        ui->num2Edit->setText(number2);
    }

    qDebug() << "number1 =" << number1 << " number2 =" << number2;
}

void MainWindow::addHandler()
{
    operand = 0;
    state = 2;
}
void MainWindow::subHandler()
{
    operand = 1;
    state = 2;
}
void MainWindow::mulHandler()
{
    operand = 2;
    state = 2;
}
void MainWindow::divHandler()
{
    operand = 3;
    state = 2;
}
void MainWindow::enterHandler()
{
    float n1 = number1.toFloat();
    float n2 = number2.toFloat();
    float result = 0;

    switch(operand)
    {
    case 0: result = n1 + n2; break;
    case 1: result = n1 - n2; break;
    case 2: result = n1 * n2; break;
    case 3:
        if(n2 != 0)
            result = n1 / n2;
        else {
            ui->resultEdit->setText("Error");
            return;
        }
        break;
    }

    ui->resultEdit->setText(QString::number(result));

    number1 = QString::number(result);
    number2 = "";
    state = 1;
}
void MainWindow::clearHandler()
{
    number1 = "";
    number2 = "";
    state = 1;

    ui->num1Edit->clear();
    ui->num2Edit->clear();
    ui->resultEdit->clear();
}
