#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <QString>

FILE *Logger::outputFile = nullptr;

Logger::Logger(){
    FILE *f = fopen(Logger::getLogFilePath(), "wb");
    if (!f)
       throw std::invalid_argument("error happened during the initialization of log file");
    this->outputFile = f;
}

void Logger::writeToFile(const char * msg, const char * data, const char * file, const int line, const char * function){
    std::fprintf(stderr, msg, data, file, line, function);
    std::fprintf(Logger::outputFile, msg, data, file, line, function);
}

const char * Logger::getLogFilePath(){
#if defined(Q_OS_LINUX) || defined(Q_OS_MAC)
    return "/usr/local/var/log/simpleread.log";
#elif Q_OS_MSDOS
    // FIX: find a correct path for Windows
    return "";
#endif
    return "";
};

void loggingHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        Logger::writeToFile("Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        Logger::writeToFile("Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        Logger::writeToFile("Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        Logger::writeToFile("Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        Logger::writeToFile("Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
};
