#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    check();
}

widget::~widget()
{
    delete ui;
}

void widget::changeMoney(int n){

    money += n;
    check();
    ui->lcdNumber->display(money);
}
void widget::subMoney(int n){
    money -= n;
    check();
    ui->lcdNumber->display(money);
}
void widget::resetMoney(){

    int money_500 = money / 500;
    money = money % 500;
    int money_100 = money / 100;
    money = money % 100;
    int money_50 = money / 50;
    money = money % 50;
    int money_10 = money / 10;
    money = 0;
    check();
    ui->lcdNumber->display(money);
    QMessageBox msg;
    msg.information(nullptr, "Return Money",QString(" 500 : %1\n 100 : %2\n 50 : %3\n 10 : %4\n").arg(money_500).arg(money_100).arg(money_50).arg(money_10));

}
void widget::check(){

    if (money >= 200){
            ui->pbCoke->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCoffee->setEnabled(true);
    }else if (money >= 100 && money < 200){
            ui->pbCoke->setEnabled(false);
            ui->pbTea->setEnabled(true);
            ui->pbCoffee->setEnabled(true);
    }else if (money >= 50 && money < 100){
            ui->pbCoke->setEnabled(false);
            ui->pbTea->setEnabled(false);
            ui->pbCoffee->setEnabled(true);
    }else if (money <= 50){
            ui->pbCoke->setEnabled(false);
            ui->pbTea->setEnabled(false);
            ui->pbCoffee->setEnabled(false);
    }


}

void widget::on_pb10_clicked()
{
    changeMoney(10);


}

void widget::on_pb50_clicked()
{
    changeMoney(50);

}

void widget::on_pb100_clicked()
{
    changeMoney(100);
}

void widget::on_pb500_clicked()
{
    changeMoney(500);
}

void widget::on_pbCoffee_clicked()
{
    subMoney(50);
}

void widget::on_pbTea_clicked()
{
    subMoney(100);
}

void widget::on_pbCoke_clicked()
{
    subMoney(200);
}

void widget::on_pbreset_clicked()
{
    resetMoney();
}
