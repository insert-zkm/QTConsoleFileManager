#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include <QTextStream>

#include "file.h"
#include "print.h"

class FileManager : public QObject {
    Q_OBJECT;
protected:
    QVector<File> m_files;
    QTimer* timer;

public:
    FileManager();
    FileManager(const QString& file_path);
    FileManager(const QVector<QString>& files_paths);
    ~FileManager();

    void track_file(const QString& file_path);
    void untrack_file(const QString& file_path);
    void start_tracking(const int msec) const;
    void stop_tracking() const;
    void show_tracking_files() const;

signals:
    void updated(const FileState& state, const File& file) const;

public slots:
    void check_files();
    void handle_update(const FileState& state, const File& file) const;

};

#endif // FILEMANAGER_H
