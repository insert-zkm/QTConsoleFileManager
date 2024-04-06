#include <QCoreApplication>
#include <QTimer>
#include <future>
#include "consolewritter.h"

#include "filetracker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker
            fi({
                   "C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_files/test_file.txt",
                   "C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_files/test_file1.txt",
                   "C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_files/test_file2.txt"
               });
    QTextStream out(stdout);

    fi.start_tracking(500);

    return a.exec();
}
