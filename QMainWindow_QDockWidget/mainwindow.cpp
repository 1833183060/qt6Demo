#include "mainwindow.h"
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //参考 https://blog.csdn.net/qq_46284579/article/details/121037942
    QDockWidget *dw1 = new QDockWidget("停靠窗口1", this);//构建停靠窗口，指定父类

    dw1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);//设置停靠窗口特性，可移动，可关闭

    dw1->setAllowedAreas(Qt::LeftDockWidgetArea);//设置可停靠区域为主窗口左边和右边
    QTextEdit *dte = new QTextEdit("DockWindow 1");
    dw1->setWidget(dte);


    addDockWidget(Qt::LeftDockWidgetArea, dw1);

    //停靠窗口2
    QDockWidget *dw2 = new QDockWidget("停靠窗口2", this);//构建停靠窗口，指定父类

    dw2->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);//设置停靠窗口特性，可浮动,可关闭
    QTextEdit *dte2 = new QTextEdit("DockWindow 2");
    dw2->setWidget(dte2);

    addDockWidget(Qt::RightDockWidgetArea, dw2);

    //停靠窗口3
    QDockWidget *dw3 = new QDockWidget("停靠窗口3", this);//构建停靠窗口，指定父类
    QTextEdit *dte3 = new QTextEdit("DockWindow 3");
    dw3->setWidget(dte3);
    addDockWidget(Qt::RightDockWidgetArea, dw3);
}

MainWindow::~MainWindow()
{
}

