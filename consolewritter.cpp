#include "consolewritter.h"

void Console::print(const QString &messege) const {
    QTextStream(stdout) << messege << Qt::endl;
}

void Console::printFileState(const FileState& fs, const File& file) const {
    QString messege = QObject::tr("%1 | size: %2 B, exists: %3, last updated time: %4, file path: %5")
            .arg(get_state_text(fs.state))
            .arg(file.size())
            .arg((file.exists() ? "yes" : "no"))
            .arg(fs.updated_time.toString("dd.MM.yy hh:mm:ss.zzz"))
            .arg(file.filePath());

    print(messege);
}
