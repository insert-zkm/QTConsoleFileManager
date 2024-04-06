#include "file.h"

File::File(const QString& file_path) : QFileInfo(file_path) {
    m_old_size = this->size();
    m_old_existance = this->exists();
}

FileState File::update_and_get_state() {
    FileState fs = {
        State::UPTODATE,
        lastModified()
    };
    this->refresh();

    if(m_old_size != this->size()) {
        fs.state = State::RESIZED;
        fs.updated_time = lastModified();

        m_old_size = this->size();
    }

    if(m_old_existance != this->exists()) {
        if(this->exists()) {

            fs.state = State::CREATED;
            QDateTime lm = lastModified();
            QDateTime bt = birthTime();
            if(lm != bt) {
                fs.state = State::RESTORED;
            }
            fs.updated_time = lastModified();
        } else {
            fs.state = State::DELETED;
            fs.updated_time = QDateTime::currentDateTime();
        }

        m_old_existance = this->exists();
    }

    return fs;
}

bool File::operator==(const File &rhs) const {
    return  static_cast<QFileInfo const &>(*this) == static_cast<QFileInfo const &>(rhs);
}


