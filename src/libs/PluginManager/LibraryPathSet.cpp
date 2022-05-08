#include "LibraryPathSet.h"
//#include <QDebug>

void CLibraryPathSet::setLibrarySearchPath(QString strPath)
{
    lockLibrarySearchPathMutex();
#ifdef Q_OS_WIN//如果是WINDOWS系统
    QString path = QString::fromLocal8Bit(qgetenv("PATH"));
    QStringList pathList= path.split(";");
    int iPathIndex=pathList.indexOf(strPath);
    if (iPathIndex<0)
    {
        QString strPathNow=strPath+";"+path;
        qputenv("PATH", strPathNow.toLocal8Bit());
        //qDebug()<<"setLibrarySearchPath:"<<strPath;
        //qDebug()<<"PathNow:"<<strPathNow;
    }
#else//LINUX
//    QString path = QString::fromLocal8Bit(qgetenv("LD_LIBRARY_PATH"));
//    QStringList pathList= path.split(":");
//    int iPathIndex=pathList.indexOf(strPath);
//    if (iPathIndex<0)
//    {
//        QString strPathNow=strPath+":"+path;
//        qputenv("LD_LIBRARY_PATH", strPathNow.toLocal8Bit());
//        qDebug()<<"setLibrarySearchPath:"<<strPath;
//        qDebug()<<"PathNow:"<<strPathNow;
//    }
#endif
    unlockLibrarySearchPathMutex();
}

void CLibraryPathSet::removeLibrarySearchPath(QString strPath)
{
    lockLibrarySearchPathMutex();
#ifdef Q_OS_WIN//如果是WINDOWS系统
    QString path = QString::fromLocal8Bit(qgetenv("PATH"));
    QStringList pathList= path.split(";");
    int iPathIndex=pathList.indexOf(strPath);
    if (iPathIndex>=0)
    {
        pathList.removeAt(iPathIndex);
        QString strPathNow=pathList.join(";");
        qputenv("PATH", strPathNow.toLocal8Bit());
        //qDebug()<<"removeLibrarySearchPath:"<<strPath;
        //qDebug()<<"PathNow:"<<strPathNow;
    }
#else//LINUX
//    QString path = QString::fromLocal8Bit(qgetenv("LD_LIBRARY_PATH"));
//    QStringList pathList= path.split(":");
//    int iPathIndex=pathList.indexOf(strPath);
//    if (iPathIndex>=0)
//    {
//        pathList.removeAt(iPathIndex);
//        QString strPathNow=pathList.join(":");
//        qputenv("LD_LIBRARY_PATH", strPathNow.toLocal8Bit());
//        qDebug()<<"removeLibrarySearchPath:"<<strPath;
//        qDebug()<<"PathNow:"<<strPathNow;
//    }
#endif
    unlockLibrarySearchPathMutex();
}

void CLibraryPathSet::lockLibrarySearchPathMutex()
{
    m_mutexLibrarySearchPath.lock();
}

void CLibraryPathSet::unlockLibrarySearchPathMutex()
{
    m_mutexLibrarySearchPath.unlock();
}
