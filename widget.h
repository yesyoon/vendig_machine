#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

    void changeMoney(int n);
    int money {0};
    void subMoney(int n);
    void resetMoney();
    void check();


private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbCoke_clicked();

    void on_pbreset_clicked();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
