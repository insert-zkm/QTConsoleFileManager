#include "file.h"

File::File(const QString& file_path) : QFileInfo(file_path) {
    m_old_size = this->size();
    m_old_existance = this->exists();
}

FileState File::update_and_get_state() {
    FileState state = {
        m_old_existance,
        false,
        false,
        m_old_size,
        lastModified()
    };
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
        if(!state.exists) {
            state.updated_time = QDateTime::currentDateTime();
        } else {
            state.updated_time = lastModified();
        }

        m_old_existance = state.exists;
    }

    return state;
}

bool File::operator==(const File &rhs) const {
    return  static_cast<QFileInfo const &>(*this) == static_cast<QFileInfo const &>(rhs);
}


