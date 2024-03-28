#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <iostream>

#include "file.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager fi("C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_file.txt");


    return a.exec();
}
