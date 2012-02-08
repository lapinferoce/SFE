#ifndef SFEFILEQUERY_H
#define SFEFILEQUERY_H


#include <QString>
#include <QFile>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFEFileQuery : public SFEQuery
{
public:
    SFEFileQuery();
//    SFEFileQuery(QFile file);
    SFEFileQuery(QString filename,QString baseDir);
    SFEFileQuery(QString baseDir);
    void dump(QByteArray array);

    void doSend();
    void doReceive();
private:
    QString _filename;
    QString _baseDir;
  //  QFile& _file;

};

#endif // SFEFILEQUERY_H
