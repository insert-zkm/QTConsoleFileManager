#ifndef FILESTATE_H
#define FILESTATE_H

#include <QDateTime>

enum State {
    STABLE,
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
        case STABLE:  return "STABLE ";
        case RESIZED: return "RESIZED";
        case DELETED: return "DELETED";
        case CREATED: return "CREATED";
        default:      return "";
    }
}

#endif // FILESTATE_H
