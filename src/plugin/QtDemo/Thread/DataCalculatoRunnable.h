#ifndef DATACALCULATORUNNABLE_H
#define DATACALCULATORUNNABLE_H

#include <QObject>
#include <QRunnable>

class DataCalculatoRunnable : public QObject, public QRunnable
{
    Q_OBJECT
public:
    DataCalculatoRunnable(QObject* parent = nullptr);
signals:
    void done(const QString& data);
public:
    virtual void run();
    void stop() {m_isStop = true;}

    bool m_isStop = false;
};

#endif // DATACALCULATORUNNABLE_H
