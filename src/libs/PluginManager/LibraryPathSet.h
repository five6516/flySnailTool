#ifndef CLIBRARYPATHSET_H
#define CLIBRARYPATHSET_H

#include <QString>
#include <QStringList>
#include <QMutex>

class CLibraryPathSet
{
public:
    CLibraryPathSet(const char *strPath)
    {
        m_strPath=strPath;
        lockLibrarySearchPathMutex();
        setLibrarySearchPath(m_strPath);
    }

    CLibraryPathSet(const QString& strPath)
    {
        m_strPath=strPath;
        lockLibrarySearchPathMutex();
        setLibrarySearchPath(m_strPath);
    }

    ~CLibraryPathSet()
    {
        removeLibrarySearchPath(m_strPath);
        unlockLibrarySearchPathMutex();
    }

private:
    void setLibrarySearchPath(QString strPath);
    void removeLibrarySearchPath(QString strPath);
    void lockLibrarySearchPathMutex();
    void unlockLibrarySearchPathMutex();

    QString m_strPath;
    QRecursiveMutex m_mutexLibrarySearchPath;
};

#endif // CEASYTEMPLIBRARYSEARCHPATH_H
