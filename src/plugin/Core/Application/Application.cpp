#include "Application.h"

CApplication::CApplication()
{

}

CApplication::~CApplication()
{

}

CApplication *CApplication::getInstance()
{
    static CApplication app;
    return &app;
}

bool CApplication::initWindow(QWidget* pQWidget)
{
    if(!pQWidget)
        return false;

    w = pQWidget;

    //寻找插件
    m_pCPluginManage->findPlugin();

    //加载插件
    m_pCPluginManage->loadPlugin(w);

    return true;
}

bool CApplication::releaseWindow()
{
    m_pCPluginManage->releasePlugin();

    return true;
}

QWidget *CApplication::mainWindow()
{
    return w;
}

QList<CPluginSpec *> *CApplication::getPluginList()
{
    return &m_pCPluginManage->m_listPlugin;
}
