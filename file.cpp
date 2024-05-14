#include "file.h"

File::File(const QString& file_path) : QFileInfo(file_path) {
    m_old_size = this->size();
    m_old_existance = this->exists();
    m_state.state = State::UPTODATE;
    m_state.updated_time = lastModified();
}

void File::refresh() {
    m_state = {
        State::UPTODATE,
        lastModified()
    };
    QFileInfo::refresh();

    if(m_old_size != this->size()) {
        m_state.state = State::RESIZED;
        m_state.updated_time = lastModified();
        m_old_size = this->size();
    }

    if(m_old_existance != this->exists()) {
        if(this->exists()) {

            m_state.state = State::CREATED;
            m_state.updated_time = lastModified();
        } else {
            m_state.state = State::DELETED;
            m_state.updated_time = QDateTime::currentDateTime();
        }

        m_old_existance = this->exists();
    }
}

FileState File::get_state() const {
    return  m_state;
}

FileState File::update_and_get_state() {
    refresh();
    return m_state;
}

bool File::operator==(const File &rhs) const {
    return  absoluteFilePath() == rhs.absoluteFilePath();
}


