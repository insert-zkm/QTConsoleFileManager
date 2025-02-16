#include "logger.h"

QString Logger::log_date() const {
    return QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss.zzz");
}

void Logger::console_log(const QString &messege) const {
    QTextStream(stdout) << messege << Qt::endl;
}

void Logger::log_head() const {
    QString head = QString("%1 | %2 | %3 | %4 | %5")
                       .arg("STATUS ", 10)
                       .arg("SIZE", 10)
                       .arg("EXISTS", 6)
                       .arg("LAST UPDATE", 21)
                       .arg("PATH");

    console_log(head);
}

void Logger::console_log_file_state(const File& file) const {
    QString messege = QString("%1 | %2 | %3 | %4 | %5")
            .arg(get_state_text(file.get_state().state), 10)
            .arg(QString::number(file.size()) + " B", 10)
            .arg((file.exists() ? "yes" : "no"), 6)
            .arg(file.get_state().updated_time.toString("dd.MM.yy hh:mm:ss.zzz"), 21)
            .arg(file.filePath());

    console_log(messege);
}
