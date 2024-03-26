#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFileInfo fi("C:/Users/Zangar/Desktop/Labs/SoftwareDev/Lab2/QTConsoleFileManager/REDME.md");
    qDebug() << fi.size();

    return a.exec();
}
