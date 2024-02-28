#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->resize(70, 30);
    ui->label->setStyleSheet("font: 11pt Times New Roman; background-color: yellow; color: red;");
    ui->label->setText("Hello World");
}

MainWindow::~MainWindow()
{
    delete ui;
}



