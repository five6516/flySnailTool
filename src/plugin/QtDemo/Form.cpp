#include "Form.h"
#include "ui_Form.h"
#include <QStringList>

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
    ui->treeWidget->setColumnCount(2);

    QStringList header;
    header << "tab" << "name";
    ui->treeWidget->setHeaderLabels(header);


}

void Form::setWidgetUi()
{

}
