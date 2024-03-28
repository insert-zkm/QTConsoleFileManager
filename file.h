#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVector>
#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QFileInfo>
#include <QDebug>

#include "logger.h"

struct FileState {
    bool exists = false;
    bool is_size_changed = false;
    bool is_existance_changed = false;
    qint64 size = 0;
    QDateTime updated_time = QDateTime();
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
    FileState get_state();

    /*!
     * \brief operator ==
     * \warning This funcition only compares QFileInfo part of File, it doesn't
     * compare m_old_size and m_old_existance.
     * \param rhs
     * \return (QFileInfo)lhs == (QFileInfo)rhs
     */
    bool operator==(const File& rhs) const;
};

class FileManager : public QObject {
    Q_OBJECT;
protected:
    QVector<File> m_files;
    QTimer* timer;

public:
    FileManager();
    FileManager(const QString& file_path);
    FileManager(const QVector<QString>& files_paths);
    ~FileManager();

    void track_file(const QString& file_path);
    void untrack_file(const QString& file_path);
    void start_tracking();
signals:
    void updated(const FileState& state) const;

public slots:
    void check_files();
};

#endif // FILE_H
