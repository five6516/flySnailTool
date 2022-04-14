#include "UiHelper.h"
#include <QWidget>

UiHelper::UiHelper()
{

}

void UiHelper::setframeless(QWidget *widget)
{
    bool tool = false;
    bool top = false;
    bool menu = true;
    //根据设定逐个追加属性
#ifdef __arm__
    widget->setWindowFlags(Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
#else
    widget->setWindowFlags(Qt::FramelessWindowHint);
#endif
    if (tool)
    {
        widget->setWindowFlags(widget->windowFlags() | Qt::Tool);
    }
    if (top)
    {
        widget->setWindowFlags(widget->windowFlags() | Qt::WindowStaysOnTopHint);
    }
    if (menu)
    {
        //如果是其他系统比如neokylin会产生系统边框
#ifdef Q_OS_WIN
        widget->setWindowFlags(widget->windowFlags() | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
#endif
    }
}
