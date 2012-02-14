#ifndef SFEFILEQUERY_H
#define SFEFILEQUERY_H


#include <QString>
#include <QFile>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFEFileListQuery : public SFEQuery
{
public:
    SFEFileListQuery();
//    SFEFileListQuery(QFile file);
    SFEFileListQuery(QString filename,QString baseDir);
    SFEFileListQuery(QString baseDir);

    void doSend();
    void doReceive();
private:
    QString _filename;
    QString _baseDir;
  //  QFile& _file;

};

#endif // SFEFILEQUERY_H
