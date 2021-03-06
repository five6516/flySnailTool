#include "Form.h"
#include "ui_Form.h"
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>

#include <QDialog>
#include <IconListDemo.h>
#include <ThreadDemo.h>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    initUi();
}

Form::~Form()
{
    delete ui;
}

void Form::initUi()
{
    setDemoListUi();
    setWidgetUi();
}

void Form::setDemoListUi()
{
    demoList << "IconDemo"
             << "ThreadDemo";

    foreach(QString str , demoList)
    {
        ui->listWidget->addItem(new QListWidgetItem(str));
    }

    connect(ui->listWidget, &QListWidget::itemPressed, this, &Form::pressList);
}

void Form::setWidgetUi()
{
    IconListDemo* pIconListDemo = new IconListDemo(this);
    ThreadDemo* pThreadDemo = new ThreadDemo(this);

    ui->stackedWidget->addWidget(qobject_cast<QWidget*>(pIconListDemo));
    ui->stackedWidget->addWidget(qobject_cast<QWidget*>(pThreadDemo));
}

void Form::pressList(QListWidgetItem *item)
{
    int index = demoList.indexOf(item->text());

    ui->stackedWidget->setCurrentIndex(index);
}
