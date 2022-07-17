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

    void setIcon(const QString& style);

public Q_SLOTS:
    void styleChange(const QString& style);
private:
    Ui::IconListDemo *ui;
};

#endif // ICONLISTDEMO_H
