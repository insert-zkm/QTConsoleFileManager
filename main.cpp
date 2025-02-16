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
    Logger &lg = Logger::get_instance();

    fi.track_file({
       PROJECT_PATH "test_files/test_file.txt",
       PROJECT_PATH "test_files/test_file1.txt",
       PROJECT_PATH "test_files/test_file2.txt"
    });

    QTimer timer; 
    QObject::connect(&timer, &QTimer::timeout, &fi, &FileTracker::check_files);
    QObject::connect(&fi, &FileTracker::updated, &lg, &Logger::console_log_file_state);


    lg.log_head();
    timer.start(500);

    return a.exec();
}
