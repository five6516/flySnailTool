#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLibrary>

#if (defined(_MSC_VER))

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
    #ifndef DBG_NEW
        #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
        #define new DBG_NEW
    #endif
#endif  // _DEBUG

#endif

int main(int argc, char *argv[])
{
#if (defined(_MSC_VER) && defined(_DEBUG))
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |  _CRTDBG_LEAK_CHECK_DF);
#endif

    //High DPI qt6 always enabled
#if (QT_VERSION < QT_VERSION_CHECK(6,0,0))
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif

    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "flySnailGui_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    /* Load Core Plugin*/
    QString coreFile = qApp->applicationDirPath() + "/Plugin/";

#if (defined(Q_OS_WIN))
    coreFile += "Core.dll";
#elif (defined(Q_OS_LINUX))
    coreFile += "libCore.so";
#endif

    using f_initializePlugin = int (*)(QWidget *parent, int argc, char *argv[]);
    using f_delayedInitialize = int (*)();
    using f_shutdownPlugin = int (*)();
    using f_pluginName = const char * (*)();
    f_initializePlugin p_initializePlugin = nullptr;
    f_delayedInitialize p_delayedInitialize = nullptr;
    f_shutdownPlugin p_shutdownPlugin = nullptr;
    f_pluginName p_pluginName = nullptr;

    QLibrary m_Lib;
    if(QLibrary::isLibrary(coreFile))
    {
        //确认是否是动态库
        m_Lib.setFileName(coreFile);
        if(m_Lib.load())//加载库成功
        {
            p_initializePlugin = (f_initializePlugin)m_Lib.resolve("initializePlugin");
            p_delayedInitialize = (f_delayedInitialize)m_Lib.resolve("delayedInitialize");
            p_shutdownPlugin = (f_shutdownPlugin)m_Lib.resolve("shutdownPlugin");
            p_pluginName = (f_pluginName)m_Lib.resolve("pluginName");

            if(p_initializePlugin == nullptr ||
               p_shutdownPlugin == nullptr ||
               p_pluginName == nullptr ||
               p_delayedInitialize == nullptr)
            {
                //showErrorDlg(QApplication::tr("Load Function Failed"));
                m_Lib.unload();
                return -1;
            }
            if(strcmp(p_pluginName(),"Core") != 0)
            {
                //showErrorDlg(QApplication::tr("Plugin not Core"));
                m_Lib.unload();
                return -1;
            }

            if(0 != p_initializePlugin(nullptr, argc, argv) || 0 !=p_delayedInitialize())
            {
                p_shutdownPlugin();
                m_Lib.unload();
                //showErrorDlg(QApplication::tr("initializePlugin Failed"));
                return -1;
            }
        }
        else
        {
            //showErrorDlg(QApplication::tr("Library not exist"));
            return -1;
        }
    }

    QObject::connect(&a, &QApplication::aboutToQuit, [&](){
        p_shutdownPlugin();
        m_Lib.unload();
    });

    return a.exec();
}
