#include "file.h"

File::File(const QString& file_path) : QFileInfo(file_path) {
    m_old_size = this->size();
    m_old_existance = this->exists();
}

bool File::is_updated() {
    this->refresh();
    if(m_old_size == this->size() && m_old_existance == this->exists()) {
        return false;
    }

    m_old_size = this->size();
    m_old_existance = this->exists();
    return true;
}

bool File::operator==(const File &rhs) const {
    return  static_cast<QFileInfo const &>(*this) == static_cast<QFileInfo const &>(rhs);
}

FileManager::FileManager() {}

FileManager::FileManager(const QString& file_path) : FileManager() {
    File fi(file_path);
    m_files.push_back(fi);
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
