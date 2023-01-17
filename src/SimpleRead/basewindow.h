#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QString>

/*!
 * \brief The BaseWindow class is an abstract class used for
 *        inherited windows to represet different
 *        kinds of files
 */
class BaseWindow
{
public:
    virtual void onOpen(const char *) = 0;

    virtual void onInit() = 0;

    virtual void onClose() = 0;

    virtual void onSave(){}
};

#endif // BASEWINDOW_H
