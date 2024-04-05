#include "filemanager.h"


FileManager::FileManager() {
    timer = new QTimer(this);

    connect(this, &FileManager::updated, this, &FileManager::handle_update);
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
    print() << "~FileManager\n";
    print().flush();
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
    print() << "Tracking files: " << m_files.size() << '\n';
    for(int i = 0; i < m_files.size(); i++) {
        print() << "\t " << i << ". " << m_files[i].absoluteFilePath() << '\n';
    }
    print().flush();
}

void FileManager::check_files() {
    for(int i = 0; i < m_files.size(); i++) {
        FileState state = m_files[i].update_and_get_state();
        if(state.is_size_changed || state.is_existance_changed) {
            emit updated(state, m_files[i]);
        }
    }
    print().flush();
}

void FileManager::handle_update(const FileState& state, const File& file) const {
    QString messege;
    messege = QObject::tr("Size: %1 B,\texists: %2,\tupdated time: %3,\tfile: %4\n")
                .arg(state.size)
                .arg((state.exists ? "true" : "false"))
                .arg(state.updated_time.toString("dd.MM.yy hh:mm:ss.zzz"))
                .arg(file.absoluteFilePath());
    print() << messege;
}




















