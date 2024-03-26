#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVector>
#include <QObject>
#include <QFileInfo>

#include "logger.h"

class File : public QFileInfo
{
protected:
    qint64         m_old_size;
    bool           m_old_existance;

public:
    File() = delete;
    File(const QString& file_path);

    bool is_updated();

    bool operator==(const File& rhs) const;
};

class FileManager : QObject {
    Q_OBJECT
protected:
    QVector<File> m_files;

public:
    FileManager();
    FileManager(const QString& file_path);
    FileManager(QVector<QString>& files_paths);

    void track_file(const QString& file_path);
    void untrack_file(const QString& file_path);
    void start_tracking();

};

#endif // FILE_H
