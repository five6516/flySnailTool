#include "Plugin.h"
#include "Global.h"
#include "Macro.h"
#include "Form.h"

Form* w = nullptr;

int initializePlugin(QWidget* parent, int argc, char *argv[])
{
    (void)argc;(void)argv;

    w = new Form(parent);
    w->hide();
    return 0;
}

int delayedInitialize()
{
    w->show();
    return 0;
}

int shutdownPlugin()
{
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
    return Plugin_Type::normal;
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
