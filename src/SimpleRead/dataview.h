#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QString>
#include <QWidget>
#include <QLabel>
#include <map>

class DataView
{
private:
    DataView* snapshot;


protected:
    std::string text;

    void appendChar(char c);

    char getChar(unsigned int i);
    bool isCharExistAt(unsigned int i);

    void saveSnapshot();

    bool compareSnapshot(int pIndex, int rIndex, std::string text);
public:
    DataView(std::string text);

    DataView() = default;

    QString getTextAsQString();
};

#endif // DATAVIEW_H
