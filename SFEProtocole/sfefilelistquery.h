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
    SFEFileListQuery(QString browseDir,QString baseDir);
    SFEFileListQuery(QString browseDir);

    QList<QString>  fileList();  

    void doSend();
    void doReceive();
private:
    QString _browseDir;
    QString _baseDir;
    QList<QString> _fl;
  //  QFile& _file;

};

#endif // SFEFILELISTQUERY_H
