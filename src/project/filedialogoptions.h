#ifndef FILEDIALOGOPTIONS_H
#define FILEDIALOGOPTIONS_H

#include <QMainWindow>
#include <QFileDialog>
#include <QList>
#include <QString>
#include <QRegularExpression>
#include <QObject>

class FileDialogOptions : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fileFilter READ fileFilter NOTIFY fileFilterChanged)
signals:
    void fileFilterChanged();
public:
//    void setFileFilter(const QString &a) {
//            if (a != m_fileFilter) {
//                m_fileFilter = a;
//                emit fileFilterChanged();
//            }
//        }
    QString fileFilter() const {
        return m_fileFilter;
    }


//    explicit FileDialog(QObject* parent = 0) : QObject(parent) {};

//    FileDialog(QMainWindow* parent);
//    bool exec();

private:
    QString m_fileFilter = "Files (*.docx *.csv *.pdf *.txt)";
//    QString getSelectedFileWithPattern(QString pattern);
////    QString getAllowedFilesFilter();

//    QFileDialog* dialog;
//    QString selectedFiles;
};

#endif // FILEDIALOGOPTIONS_H
