#ifndef PRINT_H
#define PRINT_H

#include <QTextStream>

class Print : public QTextStream
{
private:
    Print();
public:
    static Print &globalInstance();
};

inline Print& print() {
    return Print::globalInstance();
}

#endif // PRINT_H
