#ifndef SFEGETQUERY_H
#define SFEGETQUERY_H


#include <QString>
#include <QDir>
#include <QDirIterator>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFEGetQuery : public SFEQuery
{
public:
    SFEGetQuery();
//    SFEGetQuery(QFile file);
    SFEGetQuery(QString filename);

    QString filename();

    void doSend();
    void doReceive();
private:
    QString _filename;
  //  QFile& _file;

};

#endif // SFEFILELISTQUERY_H
