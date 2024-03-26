#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFileInfo fi("C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/test_file.txt");

    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&fi]() {
        fi.refresh();
        qDebug() <<"is exist: " << fi.exists() << ", last modified: " << fi.lastModified();
        fi.refresh();
    });
    timer->start(2000);
    return a.exec();
}
