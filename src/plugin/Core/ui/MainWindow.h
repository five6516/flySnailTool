#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include "PluginManage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initForm(QWidget *widget);
    void loadPlugin();

    QScopedPointer<CPluginManage> m_pCPluginManage {new CPluginManage(qApp->applicationDirPath() + "/Plugin")};
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
