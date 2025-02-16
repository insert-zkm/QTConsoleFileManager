#ifndef LOGGER_H
#define LOGGER_H

#include <QDateTime>
#include <QFile>
#include <QObject>
#include <QString>
#include <QTextStream>

#include "file.h"
#include "filestate.h"

class Logger : public QObject
{
    Q_OBJECT
private:
    Logger() = default;
    ~Logger() = default;

public:
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    inline static Logger& get_instance() {
        static Logger l_instance;
        return l_instance;
    };

    void console_log(const QString& messege) const;
    void log_head() const;

    QString log_date() const;

public slots:
    void console_log_file_state(const File& file) const;

};

#endif // LOGGER_H
