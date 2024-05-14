#ifndef FILESTATE_H
#define FILESTATE_H

#include <QDateTime>

enum State {
    UPTODATE,
    RESIZED,
    DELETED,
    CREATED
};

struct FileState {
    State       state;
    QDateTime   updated_time;
};

inline QString get_state_text(const State& st) {
    switch (st) {
    case UPTODATE:  return "UPTODATE";
    case RESIZED:   return "RESIZED ";
    case DELETED:   return "DELETED ";
    case CREATED:   return "CREATED ";
    default:        return "";
    }
}

#endif // FILESTATE_H
