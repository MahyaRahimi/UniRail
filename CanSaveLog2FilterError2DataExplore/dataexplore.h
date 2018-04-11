#ifndef DATAEXPLORE_H
#define DATAEXPLORE_H
#include "Logger.h"
#include <QCanBusFrame>

class DataExplore: public Logger {
public:
    DataExplore();
    QString time;
    QString flags;
    QByteArray datatoexplore;
    quint32 idtoexplore;
    QString text;
    void explore(const QCanBusFrame frame);
};

#endif // DATAEXPLORE_H
