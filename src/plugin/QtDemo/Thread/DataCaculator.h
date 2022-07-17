#ifndef DATACACULATOR_H
#define DATACACULATOR_H

#include <QObject>
#include <QString>
class DataCaculator : QObject
{
    Q_OBJECT
public:
    DataCaculator(QObject* parent = nullptr);

    QString cal();
};

#endif // DATACACULATOR_H
