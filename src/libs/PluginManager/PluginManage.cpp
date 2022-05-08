#include "PluginManage.h"
#include "LibraryPathSet.h"
#include <QDir>
#include <QDebug>
#include <QLockFile>
#include <QApplication>
#include <QSettings>
//#include "ui/MainWindow.h"

const char C_IGNORED_PLUGINS[] = "Plugins/Ignored";
const char C_FORCEENABLED_PLUGINS[] = "Plugins/ForceEnabled";

//extern MainWindow* w;
CPluginManage::CPluginManage(QString path)
{
    m_strPluginDir = path;
}

CPluginManage::~CPluginManage()
{

}

int CPluginManage::findPlugin()
{
    readSetting();

    QDir fileDir(m_strPluginDir);

    CLibraryPathSet easylib(m_strPluginDir.toStdString().c_str());

    fileDir.setFilter(QDir::Files);
    QFileInfoList fileInfoList = fileDir.entryInfoList();
    QStringList fileList;
    qDebug()<<fileInfoList.count();
    int i=0;
    for(int inf = 0; inf < fileInfoList.count(); inf ++)
    {
        QString fileName = fileInfoList.at(inf).absoluteFilePath();
        qDebug()<<fileName;
        CPluginSpec* pluginSpec = new CPluginSpec;
        if(pluginSpec->isPlugin(fileName))
        {
            qDebug()<<fileName<< "is Plugin";

            //配置
            if (disabledPlugins.contains(QString(pluginSpec->pluginName())))
                pluginSpec->setEnable(false);
            if (forceEnabledPlugins.contains(QString(pluginSpec->pluginName())))
                pluginSpec->setEnable(true);

            //不存在相同名字的插件，如果有，则不加载
            //if(!m_mapPlugin.contains(QString(pluginSpec->pluginName())))
            {
                pluginSpec->setIndex(i++);
                m_listPlugin.push_back(pluginSpec);
            }
            //else
            //{
            //    qDebug()<<fileName<< "has same name Plugin";
            //}
        }
        else
        {
            delete pluginSpec;pluginSpec = nullptr;
        }
    }

    return  0;
}

int CPluginManage::loadPlugin(QWidget *parent)
{
    for(auto i : m_listPlugin)
    {
        if(i->getEnable())//开启的插件才加载
            i->loadPlugin(parent);
    }

    return 0;
}

int CPluginManage::releasePlugin()
{
    for(auto i : m_listPlugin)
    {
        if(i->getEnable())//开启的插件才加载
            i->releasePlugin();
    }
    qDeleteAll(m_listPlugin);
    m_listPlugin.clear();

    return 0;
}

void CPluginManage::showManageForm()
{
//    ManageForm* pManageForm = new ManageForm(this,w);
//    pManageForm->setAttribute(Qt::WA_DeleteOnClose);
//    pManageForm->setWindowModality(Qt::ApplicationModal);
//    pManageForm->show();
}

void CPluginManage::writeSetting()
{
    QLockFile lock(qApp->applicationDirPath()+m_strSettingFile+".lck");
    QSettings settings(qApp->applicationDirPath()+m_strSettingFile,QSettings::Format::IniFormat);

    disabledPlugins.clear();
    forceEnabledPlugins.clear();

    for(auto i : m_listPlugin)
    {
        if (i->getEnable())
            forceEnabledPlugins.append(i->pluginName());
        else
            disabledPlugins.append(i->pluginName());
    }

    settings.setValue(C_IGNORED_PLUGINS,disabledPlugins);
    settings.setValue(C_FORCEENABLED_PLUGINS,forceEnabledPlugins);
}

void CPluginManage::readSetting()
{
    QLockFile lock(qApp->applicationDirPath()+m_strSettingFile+".lck");
    QSettings settings(qApp->applicationDirPath()+m_strSettingFile,QSettings::Format::IniFormat);
    disabledPlugins= settings.value(C_IGNORED_PLUGINS).toStringList();
    forceEnabledPlugins= settings.value(C_FORCEENABLED_PLUGINS).toStringList();
}
