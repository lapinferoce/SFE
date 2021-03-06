#include "sfebigfilequery.h"
#include <QBuffer>
#include <QDir>
/*SFEBigFileQuery::SFEFileQuery(QFile file):SFEQuery(SFEQuery::FILE),_file(file)
{

}*/
SFEBigFileQuery::SFEBigFileQuery():SFEQuery(SFEQuery::BIG_FILE_TYPE)
{
    _filename = "";
    _baseDir = "";
}
SFEBigFileQuery::SFEBigFileQuery(QString baseDir):SFEQuery(SFEQuery::BIG_FILE_TYPE)
{
    _filename = "";
    _baseDir = baseDir;
}
SFEBigFileQuery::SFEBigFileQuery(QString filename,QString baseDir):SFEQuery(SFEQuery::BIG_FILE_TYPE)
{
    _filename = filename;
    _baseDir = baseDir;
}
// size type filepath data
void SFEBigFileQuery::doSend()
{
      QString z = _filename.replace(_baseDir,"",Qt::CaseSensitive);
      qDebug("filename:");
      qDebug()<<z;
      _out << z;

      qDebug(">> done");

}

QString SFEBigFileQuery::filename()
{
	qDebug()<< "filename" << _filename;
	qDebug()<< "_basename"<< _baseDir;
       QString z =_filename;
	z.prepend(_baseDir);
	qDebug() << "z:" << z; 
	return z;
}

void SFEBigFileQuery::doReceive()
{
    _in >> _filename;
    qDebug("filename:=>");
    qDebug()<<_filename;

    QString filepathname =  _filename;
    filepathname.prepend(_baseDir);
    QFileInfo dfi(filepathname);
    QDir dir = dfi.absoluteDir();
    if(!dir.exists())
    {
	QDir dir2;
	if(!dir2.mkpath(dfi.absoluteDir().path()))
        {
		qDebug()<< "error directory : "<< filepathname << "does not exist and cant be created";
		return;
	}
    }
    //int pos, int len
}

