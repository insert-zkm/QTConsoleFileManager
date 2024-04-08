#include "logger.h"

Logger::Logger() {
    m_file.setFileName( "main.log");
    m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

    QString entry_messege("#Date: " + log_date() + "\n");
    if(m_file.size() != 0) {
        entry_messege = "\n\n" + entry_messege;
    } else {
        file_log("#Fields: TIME, FILE-STATE, FILE-SIZE, FILE-EXISTANCE, FILE-LAST-UPDATED-TIME, FILE-PATH\n");
    }
    file_log(entry_messege);
}

Logger::~Logger() {
    if(m_file.isOpen()) {
       m_file.close();
    }
}

void Logger::file_log(const QString &messege) {
    QTextStream in(&m_file);
    in << messege << Qt::endl;
}

QString Logger::log_date() const {
    return QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss.zzz");
}

void Logger::file_log_file_state(const File& file) {
    QString messege;
    messege = QObject::tr("%1, %2, %3 bytes, %4, %5, %6 ")
            .arg(log_date())
            .arg(get_state_text(file.get_state().state))
            .arg(file.size())
            .arg(file.exists())
            .arg(file.get_state().updated_time.toString("dd.MM.yy hh:mm:ss.zzz"))
            .arg(file.filePath());

    file_log(messege);
}

void Logger::console_log(const QString &messege) const {
    QTextStream(stdout) << messege << Qt::endl;
}

void Logger::console_log_file_state(const File& file) const {
    QString messege = QObject::tr("%1 | size: %2 B, exists: %3, last updated time: %4, file path: %5")
            .arg(get_state_text(file.get_state().state))
            .arg(file.size())
            .arg((file.exists() ? "yes" : "no"))
            .arg(file.get_state().updated_time.toString("dd.MM.yy hh:mm:ss.zzz"))
            .arg(file.filePath());

    console_log(messege);
}
