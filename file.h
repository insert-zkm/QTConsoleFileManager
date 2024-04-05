#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QDateTime>
#include <QFileInfo>

struct FileState {
    bool exists;
    bool is_size_changed;
    bool is_existance_changed;
    qint64 size;
    QDateTime updated_time;
};

class File : public QFileInfo
{
protected:
    qint64         m_old_size;
    bool           m_old_existance;

public:
    File() = delete;
    File(const QString& file_path);




    /*!
     * \brief Get file info including updated is it or not
     *
     * Refresh information about file with QFileInfo::refresh method and compare
     * with old information(m_old_size and m_old_existance). If there is a difference
     * in size or existance it returns a FileState with "FileState.is_**_changed = true" and
     * updated time.
     *
     * \return FileState
     */
    FileState update_and_get_state();



    /*!
     * \brief operator ==
     *  \warning This funcition only compares QFileInfo part of File, it doesn't
     * compare m_old_size and m_old_existance.
     *   \param rhs
     *    \return (QFileInfo)lhs == (QFileInfo)rhs
     */
    bool operator==(const File& rhs) const;
};

#endif // FILE_H
