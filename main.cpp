#include <QCoreApplication>

#include <QFile>
#include <QTimer>
#include <QObject>
#include <QDir>
#include <QDebug>

#include "logger.h"
#include "filetracker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker &fi = FileTracker::get_instance();
            fi.track_file({
                   PROJECT_PATH "/test_files/test_file.txt",
                   PROJECT_PATH "/test_files/test_file1.txt",
                   PROJECT_PATH "/test_files/test_file2.txt"
               });

    QTimer timer; 
    QObject::connect(&timer, &QTimer::timeout, &fi, &FileTracker::check_files);
    QObject::connect(&fi, &FileTracker::updated, &Logger::get_instance(), &Logger::console_log_file_state);
    QObject::connect(&fi, &FileTracker::updated, &Logger::get_instance(), &Logger::file_log_file_state);

    timer.start(500);

    return a.exec();
}
