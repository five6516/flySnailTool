#include "DataCalculatoRunnable.h"
#include <QRandomGenerator>
#include <QElapsedTimer>

DataCalculatoRunnable::DataCalculatoRunnable(QObject* parent) : QObject(parent)
{

}

void DataCalculatoRunnable::run()
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

        if(m_isStop)
            break;
    }
}
