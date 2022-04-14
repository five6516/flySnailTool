#ifndef UIHELPER_H
#define UIHELPER_H

#include <qglobal.h>

#if defined(Libs_PLUGIN_LIBRARY)
#  define UiManager_EXPORT Q_DECL_EXPORT
#else
#  define UiManager_EXPORT Q_DECL_IMPORT
#endif

class QWidget;
class UiManager_EXPORT UiHelper
{
public:
    UiHelper();

    void setframeless(QWidget *widget);
};

#endif // UIHELPER_H
