#include "IconListDemo.h"
#include "ui_IconListDemo.h"

#include <QMetaEnum>
IconListDemo::IconListDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IconListDemo)
{
    ui->setupUi(this);

    //QApplication::setStyle(style);

    ui->listWidget->clear();

    int IconIndex = 0;

    const QMetaObject &mo = QStyle::staticMetaObject;
    QMetaEnum metaEnum = mo.enumerator(mo.indexOfEnumerator("StandardPixmap"));

    while ((QStyle::StandardPixmap)IconIndex <= QStyle::SP_RestoreDefaultsButton) {
        QIcon icon = QApplication::style()->standardIcon((QStyle::StandardPixmap)IconIndex);

        ui->listWidget->addItem(new QListWidgetItem(icon,QString::number(IconIndex)));
        ui->listWidget->item(IconIndex)->setToolTip(metaEnum.key(IconIndex));

        IconIndex++;
    }

}

IconListDemo::~IconListDemo()
{
    delete ui;
}
