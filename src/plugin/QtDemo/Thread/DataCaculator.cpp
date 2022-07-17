#include "DataCaculator.h"
#include <QRandomGenerator>
#include <QElapsedTimer>

DataCaculator::DataCaculator(QObject* parent) : QObject(parent)
{

}

QString DataCaculator::cal()
{
    QRandomGenerator rand;
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

    return QString::number(t.elapsed())+ ":" + data;
}
