#ifndef TEXTWINDOWWRITE_H
#define TEXTWINDOWWRITE_H

#include <QString>

class TextWindowWrite {
public:
    virtual void onWriteText(QString, int start, int end) = 0;
};

#endif // TEXTWINDOWWRITE_H
