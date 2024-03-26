#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

class Logger
{
    QString m_logger_file;
public:
    Logger(const QString& logger_file);
};

class ConsoleDisplay {
public:
    void display(QString& messege) const;
};

#endif // LOGGER_H
