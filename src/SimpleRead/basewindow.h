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
protected:
    QString fileName;

public:
    virtual void onInit() = 0;

    virtual void onSave() = 0;

    void setFileName(QString);
};

#endif // BASEWINDOW_H
