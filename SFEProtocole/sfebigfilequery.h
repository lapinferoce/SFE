#ifndef SFEBIGFILEQUERY_H
#define SFEBIGFILEQUERY_H


#include <QString>
#include <QFile>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFEBigFileQuery : public SFEQuery
{
public:
    SFEBigFileQuery();
//    SFEBigFileQuery(QFile file);
    SFEBigFileQuery(QString filename,QString baseDir);
    SFEBigFileQuery(QString baseDir);

    QString filename();

    void doSend();
    void doReceive();
private:
    QString _filename;
    QString _baseDir;
  //  QFile& _file;

};

#endif // SFEFILEQUERY_H
