#include "Logger.h"

Logger::Logger(QString fileName, QPlainTextEdit *editor) {
    m_editor = editor;
    if (!fileName.isEmpty()) {
        file = new QFile;
        file->setFileName(fileName);
        file->open(QIODevice::Append | QIODevice::Text);
    }
}

void Logger::write( QString &value) {
    QString text = value;
    QTextStream out(file);
    out.setCodec("UTF-8");
    if (file != 0) {
        out << text;
    }
    if (m_editor != 0)
        m_editor->appendPlainText(text);
}

Logger::~Logger() {
    if (file != 0)
        file->close();
}
