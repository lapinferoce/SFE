#ifndef SFEFILELISTQUERY_H
#define SFEFILELISTQUERY_H


#include <QString>
#include <QDir>
#include <QDirIterator>

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
    QList<QString> _fl;
  //  QFile& _file;

};

#endif // SFEFILELISTQUERY_H
