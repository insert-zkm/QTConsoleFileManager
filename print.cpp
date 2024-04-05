#include "print.h"

Print::Print() : QTextStream(stdout)
{}

Print& Print::globalInstance() {
    static Print global;
    global.flush();
    return global;
}
