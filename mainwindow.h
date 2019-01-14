#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //公共槽函数
    //刷新噪点
    void slt_reflushVerification();

protected:
    //重写绘制事件,以此来生成噪点
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    long int noice_point_number ;//噪点的数量

    enum {
        NUMBER_FLAG,
        UPLETTER_FLAG,
        LOWLETTER_FLAG
    };
};

#endif // MAINWINDOW_H
