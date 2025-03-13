#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setButtonStyles();
    enableButton(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setButtonStyles()
{
    QString buttonStyle = R"(
        QPushButton { background-color: lightgreen; color: black;}
        QPushButton:disabled { background-color: darkgray; }
    )";

    ui->pbCoffee->setStyleSheet(buttonStyle);
    ui->pbMilk->setStyleSheet(buttonStyle);
    ui->pbTea->setStyleSheet(buttonStyle);
}

void Widget::enableButton(int value)
{
    ui->pbCoffee->setEnabled(value >= 100);
    ui->pbMilk->setEnabled(value >= 150);
    ui->pbTea->setEnabled(value >= 200);

    ui->lcdNumber->display(money);
}

void Widget::increaseMoney(int value)
{
    money += value;
    enableButton(money);
}

void Widget::on_pb10_clicked()
{
    increaseMoney(10);
}

void Widget::on_pb50_clicked()
{
    increaseMoney(50);
}

void Widget::on_pb100_clicked()
{
    increaseMoney(100);
}

void Widget::on_pb500_clicked()
{
    increaseMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    increaseMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    increaseMoney(-150);
}


void Widget::on_pbTea_clicked()
{
    increaseMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int r500 = money / 500;
    money %= 500;

    int r100 = money / 100;
    money %= 100;

    int r50 = money / 50;
    money %= 50;

    int r10 = money / 10;
    money %= 10;

    enableButton(money);

    QString message = QString("500: %1\n100: %2\n50: %3\n10: %4").arg(r500).arg(r100).arg(r50).arg(r10);
    mb.information(this, "Reset", message);
}


