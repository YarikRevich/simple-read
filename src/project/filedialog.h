#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QMainWindow>
#include <QFileDialog>
#include <QList>
#include <QString>

#define DOCX "^(.+)\\/([^\\/]+)\\.docx$"
#define PDF "^(.+)\\/([^\\/]+)\\.pdf$"
#define TXT "^(.+)\\/([^\\/]+)\\.txt$"
#define CSV "^(.+)\\/([^\\/]+)\\.csv$"

class FileDialog
{
public:
    FileDialog(QMainWindow* parent);
    bool exec();

private:
    QString getSelectedFileWithPattern(QString pattern);
    QString getAllowedFilesFilter();

    QFileDialog* dialog;
    QString selectedFiles;
};

#endif // FILEDIALOG_H
