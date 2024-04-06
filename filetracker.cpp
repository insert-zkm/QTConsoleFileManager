#include "filemanager.h"


FileManager::FileManager() {
    timer = new QTimer(this);

    connect(this, &FileManager::updated, &console, &Console::printFileState);
    connect(timer, &QTimer::timeout, this, &FileManager::check_files);
}

FileManager::FileManager(const QString& file_path) : FileManager() {
    File fi(file_path);
    m_files.push_back(fi);
    show_tracking_files();
}

FileManager::FileManager(const QVector<QString>& files_path) : FileManager() {
    for(int i = 0; i < files_path.size(); i++) {
        track_file(files_path[i]);
    }
    show_tracking_files();
}

FileManager::~FileManager() {
    console.print(("~FileManager"));
}

void FileManager::track_file(const QString &file_path) {
    File newFile(file_path);
    for(int i = 0; i < m_files.size(); i++) {
        if(newFile == m_files[i]) {
            return;
        }
    }
    m_files.push_back(newFile);
}

void FileManager::untrack_file(const QString &file_path) {
    for(int i = 0; i < m_files.size(); i++) {
        if(file_path == m_files[i].filePath()) {
            m_files.remove(i);
            return;
        }
    }
}

void FileManager::start_tracking(const int msec) const {
    timer->start(msec);
}

void FileManager::stop_tracking() const {
    timer->stop();
}

void FileManager::show_tracking_files() const {
    console.print("Tracking files: " + QString::number(m_files.size()));
    QString files_list;
    for(int i = 0; i < m_files.size(); i++) {
        files_list += "\t " + QString::number(i) + ". " + m_files[i].absoluteFilePath() + '\n';
    }
    console.print(files_list);
}

void FileManager::check_files() {
    for(int i = 0; i < m_files.size(); i++) {
        FileState fs = m_files[i].update_and_get_state();
        if(fs.state != State::STABLE) {
            emit updated(fs, m_files[i]);
        }
    }
}




















