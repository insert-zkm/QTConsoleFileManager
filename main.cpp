#include <QCoreApplication>

#include <QFile>
#include <QDir>
#include <QDebug>

#include "consolewritter.h"
#include "filetracker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker &fi = FileTracker::get_instance();
            fi.track_file({
                   "C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_files/test_file.txt",
                   "C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_files/test_file1.txt",
                   "C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_files/test_file2.txt"
               });

    fi.start_tracking(500);

    return a.exec();
}
