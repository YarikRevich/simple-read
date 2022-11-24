#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QString>
#include <QWidget>

class DataView
{
public:
    DataView(QWidget *parent);

    void addParagraph(QString paragraph);
    void addTable();

    void show();
private:

};

#endif // DATAVIEW_H
