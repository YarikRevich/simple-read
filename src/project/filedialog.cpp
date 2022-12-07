#include "filedialog.h"

#include "docxwindow.h"
#include "pdfwindow.h"
#include "txtwindow.h"
#include "csvwindow.h"

#include <iostream>
#include <QRegularExpression>

FileDialog::FileDialog(QMainWindow* parent)
{
    this->dialog = new QFileDialog(parent);
    this->dialog->setFileMode(QFileDialog::ExistingFile);
    this->dialog->setNameFilter(this->getAllowedFilesFilter());
    if (this->dialog->exec()){
        this->selectedFiles = this->dialog->selectedFiles().join(" ");
    }else{
        qFatal("'FileDialog' failed during execution");
    }
}

bool FileDialog::exec()
{
    QString selectedDOCXFile = this->getSelectedFileWithPattern(DOCX);
    if (!selectedDOCXFile.isEmpty()){
            DOCXWindow *docxwindow = new DOCXWindow(selectedDOCXFile);
            docxwindow->show();
            return true;
    }

    QString selectedPDFFile = this->getSelectedFileWithPattern(PDF);
    if (!selectedPDFFile.isEmpty()){
            PDFWindow *pdfwindow = new PDFWindow(selectedPDFFile);
            pdfwindow ->show();
            return true;
    }

    QString selectedCSVFile = this->getSelectedFileWithPattern(CSV);
    if (!selectedCSVFile.isEmpty()){
            CSVWindow *csvwindow = new CSVWindow(selectedCSVFile);
            csvwindow ->show();
            return true;
    }

    QString selectedTXTFile = this->getSelectedFileWithPattern(TXT);
    if (!selectedTXTFile.isEmpty()){
            TXTWindow *txtwindow = new TXTWindow(selectedTXTFile);
            txtwindow->show();
            return true;
    }
    return false;
}

QString FileDialog::getSelectedFileWithPattern(QString pattern){
    QRegularExpression re(pattern);
    QRegularExpressionMatch match = re.match(this->selectedFiles);
    if (match.hasMatch()){
        return match.captured(0);
    }

    return "";
}

QString FileDialog::getAllowedFilesFilter(){
    return "Files (*.docx *.csv *.pdf *.txt)";
}
