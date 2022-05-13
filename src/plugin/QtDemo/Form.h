#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class QListWidgetItem;
class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public Q_SLOTS:
    void pressList(QListWidgetItem *item);
private:
    Ui::Form *ui;

    void initUi();
    void setDemoListUi();
    void setWidgetUi();

    QStringList demoList;
};

#endif // FORM_H
