#include "mainwindow.h"
#include <QDockWidget>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar* menuBar = this->menuBar();

    QMenu* menu = menuBar->addMenu( "菜单" );
    QAction* act = new QAction(tr("&O无参数1"), this);
    act->setShortcuts(QKeySequence::Open);
    act->setStatusTip(tr("无参数1"));
    connect(act, &QAction::triggered, this, &MainWindow::fun1);

    menu->addAction(act);
    menu->addAction("无参数2",this,&MainWindow::fun2);
    menu->addAction( "带参数1", this, std::bind(&MainWindow::funWithParam,this,"参数 1" ));
    menu->addAction(tr("带参数 2"),this,
                    [=]() {
        this->funWithParam("参数 2");
    });
}

MainWindow::~MainWindow()
{
}

void MainWindow::fun1()
{
    QMessageBox::information(this,"","无参数1");
}

void MainWindow::fun2()
{
    QMessageBox::information(this,"","无参数2");
}

void MainWindow::funWithParam(QString s)
{
    QMessageBox::information(this,"",s);
}

