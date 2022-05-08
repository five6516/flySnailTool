#ifndef ICONLISTDEMO_H
#define ICONLISTDEMO_H

#include <QWidget>

namespace Ui {
class IconListDemo;
}

class IconListDemo : public QWidget
{
    Q_OBJECT

public:
    explicit IconListDemo(QWidget *parent = nullptr);
    ~IconListDemo();

private:
    Ui::IconListDemo *ui;
};

#endif // ICONLISTDEMO_H
