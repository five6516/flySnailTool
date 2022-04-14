#include "Plugin.h"
#include "Global.h"
#include "Macro.h"
#include "ui/MainWindow.h"

MainWindow* w = nullptr;

void appInit()
{

}

int initializePlugin(int argc, char *argv[])
{
    (void)argc;(void)argv;

    appInit();

    w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->hide();
    return 0;
}

int delayedInitialize()
{
    //w->InitMachineConfig();
    //w->InitPluginugin();
    w->show();
    return 0;
}

int shutdownPlugin()
{
    //w->deleteLater();
    return 0;
}

const char *pluginName()
{
    return PROJECT_NAME;
}

const char *pluginCategory()
{
    return PROJECT_NAME;
}

Plugin_Type pluginType()
{
    return Plugin_Type::core;
}

const char *pluginVersion()
{
    return PROJECT_VERSION;
}

const char *pluginDescription()
{
    return PROJECT_DESCRIPTION;
}

const char *pluginLicense()
{
    return "";
}

QWidget *pluginWidget()
{
    return w;
}
