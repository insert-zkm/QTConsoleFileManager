#include "filetracker.h"


FileTracker::FileTracker() {
    timer = new QTimer(this);

    connect(this, &FileTracker::updated, &console, &Console::printFileState);
    connect(timer, &QTimer::timeout, this, &FileTracker::check_files);
}

FileTracker &FileTracker::get_instance() {
    static FileTracker ft_instance;
    return ft_instance;
}

FileTracker::~FileTracker() {
    console.print(("~FileManager"));
}

void FileTracker::track_file(const QString &file_path) {
    File newFile(file_path);
    for(int i = 0; i < m_files.size(); i++) {
        if(newFile == m_files[i]) {
            return;
        }
    }
    m_files.push_back(newFile);
}

void FileTracker::track_file(const QVector<QString> &file_paths) {
    for(int i = 0; i < file_paths.size(); i++) {
        track_file(file_paths[i]);
    }
}

void FileTracker::untrack_file(const QString &file_path) {
    for(int i = 0; i < m_files.size(); i++) {
        if(file_path == m_files[i].filePath()) {
            m_files.remove(i);
            return;
        }
    }
}

void FileTracker::start_tracking(const int msec) const {
    timer->start(msec);
}

void FileTracker::stop_tracking() const {
    timer->stop();
}

void FileTracker::check_files() {
    for(int i = 0; i < m_files.size(); i++) {
        FileState fs = m_files[i].update_and_get_state();
        if(fs.state != State::UPTODATE) {
            emit updated(fs, m_files[i]);
        }
    }
}




















