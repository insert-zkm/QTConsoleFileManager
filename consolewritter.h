#ifndef CONSOLEWRITTER_H
#define CONSOLEWRITTER_H

#include <QObject>
#include <QTextStream>
#include <QString>

#include "file.h"
#include "filestate.h"

class Console : public QObject
{
    Q_OBJECT
private:
    Console() = default;
    ~Console() = default;

public:
    Console(const Console&) = delete;
    void operator=(const Console&) = delete;

    inline static Console& get_instance() {
        static Console c_instance;
        return c_instance;
    };
    void print(const QString& messege) const;

public slots:
    void print_file_state(const FileState& fs, const File& file) const;
};

#endif // CONSOLEWRITTER_H
