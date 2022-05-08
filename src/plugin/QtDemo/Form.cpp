#include "Form.h"
#include "ui_Form.h"
#include <QStringList>
#include <QListWidgetItem>


#include <IconListDemo.h>

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
    QStringList header;
    header << "tab" << "name";
    ui->listWidget->addItem(new QListWidgetItem("sss"));


}

void Form::setWidgetUi()
{
    IconListDemo* pIconListDemo = new IconListDemo();
    ui->stackedWidget->addWidget(reinterpret_cast<QWidget*>(pIconListDemo));
}
