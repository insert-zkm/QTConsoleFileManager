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
public:
    void print(const QString& messege) const;

public slots:
    void printFileState(const FileState& fs, const File& file) const;
};

#endif // CONSOLEWRITTER_H
