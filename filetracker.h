#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include <QTextStream>

#include "consolewritter.h"
#include "file.h"
#include "filestate.h"

class FileTracker : public QObject {
    Q_OBJECT;
protected:
    QVector<File> m_files;
    QTimer* timer;

    Console console;

public:
    FileTracker();
    FileTracker(const QString& file_path);
    FileTracker(const QVector<QString>& files_paths);
    ~FileTracker();

    void track_file(const QString& file_path);
    void untrack_file(const QString& file_path);
    void start_tracking(const int msec) const;
    void stop_tracking() const;
    void show_tracking_files() const;

signals:
    void updated(const FileState& state, const File& file) const;

public slots:
    void check_files();

};

#endif // FILETRACKER_H
