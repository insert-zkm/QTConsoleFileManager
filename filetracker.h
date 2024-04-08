#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QVector>
#include <QTextStream>

#include "file.h"
#include "filestate.h"

class FileTracker : public QObject {
    Q_OBJECT;
protected:
    QVector<File> m_files;

    FileTracker();
    ~FileTracker();

public:
    FileTracker(const FileTracker&) = delete;
    void operator=(const FileTracker&) = delete;

    static FileTracker& get_instance();

    void track_file(const QString& file_path);
    void track_file(const QVector<QString>& file_paths);
    void untrack_file(const QString& file_path);

public slots:
    void check_files();

signals:
    void updated(const File& file) const;

};

#endif // FILETRACKER_H
