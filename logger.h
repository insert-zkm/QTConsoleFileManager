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
    Logger();
    ~Logger();

protected:
    QFile m_file;

public:
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    inline static Logger& get_instance() {
        static Logger l_instance;
        return l_instance;
    };

    void log(const QString& messege);
    QString log_date() const;

public slots:
    void log_file_state(const FileState& fs, const File& file);

};

#endif // LOGGER_H
