#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QString>
#include "textwindowread.h"
#include "textwindowwrite.h"

class TextWindow : public TextWindowRead, public TextWindowWrite
{
public:
    virtual int getContentSize() = 0;
};

#endif // TEXTWINDOW_H
