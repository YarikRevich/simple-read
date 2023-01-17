#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include "qmlwindow.h"

#include <QtCore/qtmetamacros.h>
#include <QObject>
#include <QString>

/*!
 * \class FileWindow
 * \brief The FileWindow class is an abstract class used for
 *        inherited windows to represet different
 *        kinds of files
 */
class FileWindow : public QMLWindow{
public:

protected:
       virtual void onSave() = 0;


};

#endif // FILEWINDOW_H
