#ifndef TEXTWINDOWREAD_H
#define TEXTWINDOWREAD_H

#include <QString>

class TextWindowRead
{
public:
    virtual QString onReadText(int start, int end) = 0;
};

#endif // TEXTWINDOWREAD_H
