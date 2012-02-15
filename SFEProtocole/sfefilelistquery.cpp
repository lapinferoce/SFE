#include "sfefilelistquery.h"
#include <QBuffer>
#include <QMutableListIterator>

SFEFileListQuery::SFEFileListQuery():SFEQuery(SFEQuery::LIST_TYPE)
{
    _browseDir = "";
    _baseDir = "";
}
SFEFileListQuery::SFEFileListQuery(QString browseDir):SFEQuery(SFEQuery::LIST_TYPE)
{
    _browseDir = browseDir;
    _baseDir = "";
}
SFEFileListQuery::SFEFileListQuery(QString browseDir ,QString baseDir):SFEQuery(SFEQuery::LIST_TYPE)
{
    _browseDir = browseDir;
    _baseDir = baseDir;
}
QList<QString> SFEFileListQuery::fileList()
{
	return _fl;
}
// size type filepath data
void SFEFileListQuery::doSend()
{

     QDirIterator directory_walker(_browseDir, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
     while(directory_walker.hasNext())
     {
	directory_walker.next();
	QString s = directory_walker.fileInfo().filePath();
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
    while( javaIter.hasNext() ){
		QString s = javaIter.next();
    		_fl << s ;//javaIter.next()//.prepend(_baseDir);
		qDebug() << s;
	}
}























/*
fileQuery fq(file);
protocole.send(fq);

protocole.recieve();
*/
