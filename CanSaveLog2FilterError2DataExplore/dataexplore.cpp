#include "mainwindow.h"
#include "dataexplore.h"
#include <QByteArray>
#include <QCanBus>
#include <QCanBusFrame>
#include <QCloseEvent>
#include <QDesktopServices>
#include <QTimer>

DataExplore::DataExplore(){

}

QString DataExplore::explore(const QCanBusFrame frame){
    idtoexplore=frame.frameId();
    datatoexplore=frame.payload();
    time = QString::fromLatin1("%1.%2  ")
           .arg(frame.timeStamp().seconds(), 10, 10, QLatin1Char(' '))
           .arg(frame.timeStamp().microSeconds() / 100, 4, 10, QLatin1Char('0'));

    flags = frameFlags(frame);

    /*define the file "CanLog.txt" to log the data frames into:*/
    QPlainTextEdit *editor = new QPlainTextEdit();
    QString fileName = "c:CanLog.txt";
    Logger *logger = new Logger(fileName, editor);

    /*if the frame data equals to a Crash Fault (0FC):*/
    if (idtoexplore==0xFC)
    {

        /* if(datatoexplore[0]==0x01){

         }*/


        /*write in log file "CanLog.txt":*/
        text=time.append(flags).append("     0FC   Crash Fault\n");
        logger->write(text);
        /*send text to the user interface:*/
        return text;

    /*if the frame data equals to a Default Fault (0FD):*/
    }else if (idtoexplore==0xFD)
    {
        /*write in log file "CanLog.txt":*/
        text=time.append(flags).append("     0FD   Default Fault\n");
        logger->write(text);
        /*send text to the user interface:*/
        return text;

    /*if the frame data is not an error frame:*/
    }else
    {
        /*Doesn't show other frames:*/
        return -1;
    }

}

static QString frameFlags(const QCanBusFrame &frame)
{
    QString result = QLatin1String(" --- ");

    if (frame.hasBitrateSwitch())
        result[1] = QLatin1Char('B');
    if (frame.hasErrorStateIndicator())
        result[2] = QLatin1Char('E');
    if (frame.hasLocalEcho())
        result[3] = QLatin1Char('L');

    return result;
}
