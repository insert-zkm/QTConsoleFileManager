#include "file.h"

File::File(const QString& file_path) : QFileInfo(file_path) {
    m_old_size = this->size();
    m_old_existance = this->exists();
}

FileState File::get_state() {
    FileState state = {};
    this->refresh();

    if(m_old_size != this->size()) {
        state.is_size_changed = true;
        state.size = this->size();
        state.updated_time = lastModified();

        m_old_size = state.size;
    }

    if(m_old_existance != this->exists()) {
        state.is_existance_changed = true;
        state.exists = this->exists();
        state.updated_time = lastModified();

        m_old_existance = state.exists;
    }

    return state;
}

bool File::operator==(const File &rhs) const {
    return  static_cast<QFileInfo const &>(*this) == static_cast<QFileInfo const &>(rhs);
}

FileManager::FileManager() {
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &FileManager::updated);
    timer->start(2000);
    FileState();
}

FileManager::FileManager(const QString& file_path) : FileManager() {
    File fi(file_path);
    m_files.push_back(fi);
}

FileManager::FileManager(const QVector<QString>& files_path) : FileManager() {
    for(int i = 0; i < files_path.size(); i++) {
        track_file(files_path[i]);
    }
}

FileManager::~FileManager() {
    if(timer) {
        delete timer;
    }
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

void FileManager::check_files() {
    for(int i = 0; i < m_files.size(); i++) {
        FileState state = m_files[i].get_state();
        if(state.is_size_changed || state.is_existance_changed) {
            emit updated(state);
        }
    }
}
