#ifndef DATACALCULATORTHREAD_H
#define DATACALCULATORTHREAD_H

#include <QThread>

class DataCalculatorThread : public QThread
{
    Q_OBJECT
public:
    DataCalculatorThread(QObject* parent = nullptr);

signals:
    void done(const QString& data);
public:
    void run() override;
};

#endif // DATACALCULATORTHREAD_H
