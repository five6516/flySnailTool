#ifndef PLUGINMANAGE_H
#define PLUGINMANAGE_H

#include <QString>
#include <QList>
#include "PluginSpec.h"
//#include "ManageForm.h"

class CPluginManage
{
public:
    explicit CPluginManage(QString path);
    CPluginManage(const CPluginManage&) = delete ;
    CPluginManage& operator=(const CPluginManage&) = delete ;
    ~CPluginManage();

    int findPlugin();
    int loadPlugin(QWidget *parent);
    int releasePlugin();
    void showManageForm();
    void writeSetting();
    void readSetting();

    QList<CPluginSpec*> m_listPlugin;//插件管理类
    QString m_strPluginDir;
    QString m_strSettingFile="/config/Plugin.ini";
private:
    QStringList disabledPlugins;
    QStringList forceEnabledPlugins;

};

#endif // PLUGINMANAGE_H
