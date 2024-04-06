#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QVector>
#include <QTimerEvent>
#include <QTextStream>

#include "consolewritter.h"
#include "file.h"
#include "filestate.h"

class FileTracker : public QObject {
    Q_OBJECT;
protected:
    QVector<File> m_files;
    int timer_id;
    Console console;

    FileTracker();
    FileTracker(const QString& file_path);
    FileTracker(const QVector<QString>& files_paths);
    ~FileTracker();

public:
    FileTracker(const FileTracker&) = delete;
    void operator=(const FileTracker&) = delete;

    static FileTracker& get_instance();

    void timerEvent(QTimerEvent* event);

    void track_file(const QString& file_path);
    void track_file(const QVector<QString>& file_paths);
    void untrack_file(const QString& file_path);
    void start_tracking(const int msec);
    void stop_tracking();

signals:
    void updated(const FileState& state, const File& file) const;

public slots:
    void check_files();

};

#endif // FILETRACKER_H
