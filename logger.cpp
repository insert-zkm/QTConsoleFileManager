#include "logger.h"

QString Logger::log_date() const {
    return QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss.zzz");
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
