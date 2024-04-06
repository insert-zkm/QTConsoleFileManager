#include "filetracker.h"


FileTracker::FileTracker() {
    timer = new QTimer(this);

    connect(this, &FileTracker::updated, &console, &Console::printFileState);
    connect(timer, &QTimer::timeout, this, &FileTracker::check_files);
}

FileTracker::FileTracker(const QString& file_path) : FileTracker() {
    File fi(file_path);
    m_files.push_back(fi);
    show_tracking_files();
}

FileTracker::FileTracker(const QVector<QString>& files_path) : FileTracker() {
    for(int i = 0; i < files_path.size(); i++) {
        track_file(files_path[i]);
    }
    show_tracking_files();
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

void FileTracker::show_tracking_files() const {
    console.print("Tracking files: " + QString::number(m_files.size()));
    QString files_list;
    for(int i = 0; i < m_files.size(); i++) {
        files_list += "\t " + QString::number(i) + ". " + m_files[i].absoluteFilePath() + '\n';
    }
    console.print(files_list);
}

void FileTracker::check_files() {
    for(int i = 0; i < m_files.size(); i++) {
        FileState fs = m_files[i].update_and_get_state();
        if(fs.state != State::UPTODATE) {
            emit updated(fs, m_files[i]);
        }
    }
}




















