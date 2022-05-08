#ifndef APPLICATION_H
#define APPLICATION_H

#include "Global.h"
#include "PluginManage.h"

#define cApp CApplication::getInstance()

class QWidget;
class CApplication
{
public:
    static CApplication* getInstance();

    bool initWindow(QWidget* pQWidget);
    bool releaseWindow();
    QWidget* mainWindow();
    QList<CPluginSpec*>* getPluginList();

private:
    CApplication();
    ~CApplication();

    CApplication(const CApplication&) = delete;
    CApplication& operator=(CApplication&) = delete;
    CApplication(const CApplication&&) = delete;
    CApplication& operator=(CApplication&&) = delete;

    QWidget* w = nullptr;

    QScopedPointer<CPluginManage> m_pCPluginManage {new CPluginManage(qApp->applicationDirPath() + "/Plugin")};
};


#endif // APPLICATION_H
