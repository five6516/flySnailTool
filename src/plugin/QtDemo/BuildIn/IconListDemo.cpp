#include "IconListDemo.h"
#include "ui_IconListDemo.h"

#include <QStyleFactory>
#include <QMetaEnum>
IconListDemo::IconListDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IconListDemo)
{
    ui->setupUi(this);

    //Style类型
    ui->comboBox->addItems(QStyleFactory::keys());

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &IconListDemo::styleChange);

    styleChange(QStyleFactory::keys().first());
}

IconListDemo::~IconListDemo()
{
    delete ui;
}

void IconListDemo::setIcon(const QString &style)
{
    this->setStyle(QStyleFactory::create(style));
    this->style()->setParent(this); //QStyleFactory::create 会new对象，需要自己处理释放，不然会内存泄漏
    //QApplication::setStyle(style);

    ui->listWidget->clear();

    int IconIndex = 0;

    const QMetaObject &mo = QStyle::staticMetaObject;
    QMetaEnum metaEnum = mo.enumerator(mo.indexOfEnumerator("StandardPixmap"));

    //也可以如下直接获取
    //QMetaEnum metaEnum = QMetaEnum::fromType<QStyle::StandardPixmap>();

    while ((QStyle::StandardPixmap)IconIndex < metaEnum.keyCount() - 1) {
        QIcon icon = this->style()->standardIcon((QStyle::StandardPixmap)IconIndex);

        ui->listWidget->addItem(new QListWidgetItem(icon,QString::number(IconIndex)));
        ui->listWidget->item(IconIndex)->setToolTip(metaEnum.key(IconIndex));

        IconIndex++;
    }
}

void IconListDemo::styleChange(const QString &style)
{
    setIcon(style);
}
