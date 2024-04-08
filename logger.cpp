#include "logger.h"

Logger::Logger() {
    m_file.setFileName( "main.log");
    m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

    QString entry_messege("#Date: " + log_date() + "\n");
    if(m_file.size() != 0) {
        entry_messege = "\n\n" + entry_messege;
    } else {
        log("#Fields: TIME, FILE-STATE, FILE-SIZE, FILE-EXISTANCE, FILE-LAST-UPDATED-TIME, FILE-PATH\n");
    }
    log(entry_messege);
}

Logger::~Logger() {
    if(m_file.isOpen()) {
       m_file.close();
    }
}

void Logger::log(const QString &messege) {
    QTextStream in(&m_file);
    in << messege << Qt::endl;
}

QString Logger::log_date() const {
    return QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss.zzz");
}

void Logger::log_file_state(const FileState& fs, const File& file) {
    QString messege;
    messege = QObject::tr("%1, %2, %3 bytes, %4, %5, %6 ")
            .arg(log_date())
            .arg(get_state_text(fs.state))
            .arg(file.size())
            .arg(file.exists())
            .arg(fs.updated_time.toString("dd.MM.yy hh:mm:ss.zzz"))
            .arg(file.filePath());

    log(messege);
}
