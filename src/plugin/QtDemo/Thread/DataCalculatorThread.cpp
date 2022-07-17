#include "DataCalculatorThread.h"
#include <QRandomGenerator>
#include <QElapsedTimer>

DataCalculatorThread::DataCalculatorThread(QObject* parent) : QThread(parent)
{

}

void DataCalculatorThread::run()
{
    QRandomGenerator rand;
    Q_FOREVER
    {
        QElapsedTimer t;
        t.start();

        QString data;
        const char* nucleabases = "CGAT";

        for(int i = 0; i < 5; i ++)
        {
            for(int k = 0; k < 80; k++)
            {
                int index = rand.bounded(0,4);
                data.append(nucleabases[index]);

                for(int j = 0; j < 5000000; j++)
                    ;
            }
        }
        emit done(QString::number(t.elapsed())+ ":thread:" + data);

        if(isInterruptionRequested())
            break;
    }
}
