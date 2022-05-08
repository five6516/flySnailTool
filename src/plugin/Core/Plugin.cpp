#include "Plugin.h"
#include "Global.h"
#include "Macro.h"
#include "ui/MainWindow.h"
#include "Application.h"

void appInit()
{

}

int initializePlugin(QWidget* parent, int argc, char *argv[])
{
    (void)argc;(void)argv;(void)parent;

    appInit();

    MainWindow* w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->hide();

    cApp->initWindow(w);

    w->initForm(w);

    return 0;
}

int delayedInitialize()
{
    //w->InitMachineConfig();
    //w->InitPluginugin();
    cApp->mainWindow()->show();
    return 0;
}

int shutdownPlugin()
{
    cApp->releaseWindow();

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
    return Plugin_Type::PLUGIN_CORE;
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
    return cApp->mainWindow();
}
