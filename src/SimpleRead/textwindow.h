#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include "textwindowread.h"
#include "textwindowwrite.h"

#include <QString>

class TextWindow : public TextWindowRead, public TextWindowWrite
{
};

#endif // TEXTWINDOW_H
