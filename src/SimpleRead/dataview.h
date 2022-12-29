#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QString>
#include <QWidget>
#include <QLabel>

class DataView
{
public:
    DataView(QWidget *parent);

    void addParagraph(QString paragraph);

    void show();
private:
    QWidget *parent;
};

#endif // DATAVIEW_H