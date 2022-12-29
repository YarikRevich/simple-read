#ifndef LOGGER_H
#define LOGGER_H

#include <QtGlobal>
#include <stdexcept>

class Logger {
public:
    Logger();

    static FILE * outputFile;

    static void writeToFile(const char * msg, const char * data, const char * file, const int line, const char * function);

    static const char * getLogFilePath();
};

void loggingHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // LOGGER_H
