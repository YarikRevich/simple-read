#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QString>
#include <QWidget>
#include <QLabel>
#include <map>

class DataView
{
public:
    DataView(QWidget *parent);

    void addParagraph(int index, QString paragraph);
private:

};

#endif // DATAVIEW_H
