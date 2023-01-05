#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include "qmlwindow.h"

#include <QtCore/qtmetamacros.h>
#include <QObject>
#include <QString>

/*!
 * \brief The FileWindow class is an abstract class used for
 *        the definition of inherited windows to represet different
 *        kinds of files
 */
class FileWindow : public QMLWindow{
public:
       void setFileName(QString);
protected:
       virtual void onInit() = 0;

       virtual void onSave() = 0;

       virtual void onWriteText(QString) = 0;

       virtual QString onRead() = 0;

       QString fileName;
};

#endif // FILEWINDOW_H
