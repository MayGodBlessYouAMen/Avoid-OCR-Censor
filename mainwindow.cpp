#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QTime>
#include <QTextCodec>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //中文支持
    setlocale(LC_CTYPE, "zh_CN.GB2312");
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//重写绘制事件,以此来生成噪点
void  MainWindow::paintEvent(QPaintEvent *event)
{

    qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec());//生成随机种子
    noice_point_number = (this->width())*15;//根据窗口大小调整噪点数
    QPainter painter(this);
    QPoint p;
    //背景设为白色
    painter.fillRect(this->rect(), Qt::white);
    //绘制噪点
    for (long int x = 0; x < ((ui->lineEdit->text().toInt())%10); ++x){//根据噪点强度重复绘制噪点
    for (long int j = 0; j < noice_point_number; ++j)
    {
        p.setX(qrand() % this->width());
        p.setY(qrand() % this->height());
        painter.setPen(QColor(qrand() % 255, qrand() % 255, qrand() % 255));
        painter.drawPoint(p);
    }
    }

    return;
}
//拖动窗口时进行刷新
void  MainWindow::slt_reflushVerification()
{
    repaint();
}
