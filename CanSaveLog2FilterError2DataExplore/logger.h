#ifndef LOGGER_H
#define LOGGER_H
#include <QApplication>
#include <QObject>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>

class Logger : public QObject
{
     Q_OBJECT
public:
     explicit Logger(QString fileName, QPlainTextEdit *editor = 0);
     ~Logger();

private:
     QFile *file;
     QPlainTextEdit *m_editor;

signals:

public slots:
     void write(QString &value);

};

#endif // LOGGER_H
