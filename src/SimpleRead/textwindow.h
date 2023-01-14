#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QString>

class TextWindow
{
public:
    virtual void onWriteText(QString, int start, int end) = 0;

    virtual QString onReadText(int start, int end) = 0;

    virtual int getContentSize() = 0;
};

#endif // TEXTWINDOW_H
