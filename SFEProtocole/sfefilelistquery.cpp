#include "sfefilelistquery.h"
#include <QBuffer>
#include <QMutableListIterator>

SFEFileListQuery::SFEFileListQuery():SFEQuery(SFEQuery::LIST_TYPE)
{
    _filename = "";
    _baseDir = "";
}
SFEFileListQuery::SFEFileListQuery(QString baseDir):SFEQuery(SFEQuery::LIST_TYPE)
{
    _filename = "";
    _baseDir = baseDir;
}
SFEFileListQuery::SFEFileListQuery(QString filename,QString baseDir):SFEQuery(SFEQuery::LIST_TYPE)
{
    _filename = filename;
    _baseDir = baseDir;
}
// size type filepath data
void SFEFileListQuery::doSend()
{
      QFile fileToSend(_filename);

     QDirIterator directory_walker(_filename, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
     while(directory_walker.hasNext())
     {
	directory_walker.next();
	QString s = directory_walker.fileInfo().fileName();
	QString z = s.replace(_baseDir,"",Qt::CaseSensitive);
	_fl << z;
	qDebug() << z;
     }
      _out << _fl;
      qDebug(">> done");

}

void SFEFileListQuery::doReceive()
{
    QList<QString> fl;
    _in >> fl;
    qDebug("fl:");
    QMutableListIterator<QString> javaIter( fl );
    while( javaIter.hasNext() )
    		_fl << javaIter.next().prepend(_baseDir);

}























/*
fileQuery fq(file);
protocole.send(fq);

protocole.recieve();
*/
