#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QObject>
#include <QString>

#include "file.h"
#include "filestate.h"

class Logger : QObject
{
Q_OBJECT

public:
    Logger() = delete;
    Logger(const QString& file_name);
    ~Logger();

    void log(const QString& messege) const;

public slots:
    void log_file_state(const FileState& fs, const File& file) const;

};

#endif // LOGGER_H
