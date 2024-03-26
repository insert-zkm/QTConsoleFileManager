#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVector>
#include <QObject>
#include <QFileInfo>

#include "logger.h"

class File : QFileInfo
{
protected:
    int         m_old_size;

public:
    File() = delete;
    File(const QString& file_path);

};

class FileManager : QObject {
    Q_OBJECT;
protected:
    QVector<File> m_files;

public:
    FileManager();
    FileManager(QVector<QString>& files_absolute_paths);

    int track_file(const QString& absolute_path);
    void untrack_file(const int& file_id);
    void untrack_file(const QString& file_name);
    int get_id(const QString& file_name) const;
    void start_tracking();

signals:
    void updated();
};

#endif // FILE_H
