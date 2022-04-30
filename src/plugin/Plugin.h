#ifndef FlySnail_PLUGIN_H
#define FlySnail_PLUGIN_H
#include <QtCore/qglobal.h>
#include <QWidget>

#if defined(FlySnail_PLUGIN_LIBRARY)
#  define FlySnail_PLUGIN Q_DECL_EXPORT
#else
#  define FlySnail_PLUGIN Q_DECL_IMPORT
#endif

typedef enum{
    core = 0,
    normal,
    pop,
    server
}Plugin_Type;

//插件过程  initializePlugin->delayedInitialize->using->shutdownPlugin

extern "C" FlySnail_PLUGIN int initializePlugin(QWidget* parent, int argc, char *argv[]);
extern "C" FlySnail_PLUGIN int delayedInitialize();
extern "C" FlySnail_PLUGIN int shutdownPlugin();

//导出一些基础信息
extern "C" FlySnail_PLUGIN QWidget* pluginWidget();//初始化界面
extern "C" FlySnail_PLUGIN const char *pluginCategory();
extern "C" FlySnail_PLUGIN const char *pluginName();
extern "C" FlySnail_PLUGIN Plugin_Type pluginType();//插件类型
extern "C" FlySnail_PLUGIN const char *pluginVersion();
extern "C" FlySnail_PLUGIN const char *pluginDescription();
extern "C" FlySnail_PLUGIN const char *pluginLicense();

#endif // QT_PL_PYSCRIPT_H
