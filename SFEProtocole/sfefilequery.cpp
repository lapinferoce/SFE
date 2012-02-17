#include "sfefilequery.h"
#include <QBuffer>
#include <QDir>
/*SFEFileQuery::SFEFileQuery(QFile file):SFEQuery(SFEQuery::FILE),_file(file)
{

}*/
SFEFileQuery::SFEFileQuery():SFEQuery(SFEQuery::FILE_TYPE)
{
    _filename = "";
    _baseDir = "";
}
SFEFileQuery::SFEFileQuery(QString baseDir):SFEQuery(SFEQuery::FILE_TYPE)
{
    _filename = "";
    _baseDir = baseDir;
}
SFEFileQuery::SFEFileQuery(QString filename,QString baseDir):SFEQuery(SFEQuery::FILE_TYPE)
{
    _filename = filename;
    _baseDir = baseDir;
}
// size type filepath data
void SFEFileQuery::doSend()
{
      QFile fileToSend(_filename);

      if (!fileToSend.open(QIODevice::ReadOnly))
      {
            qDebug("Failed!! file not found");
      }


      QByteArray blob = fileToSend.readAll();
      //const QString & before, const QString & after, Qt::CaseSensitivity cs = Qt::CaseSensitive )
      QString z = _filename.replace(_baseDir,"",Qt::CaseSensitive);
      qDebug("filename");
      qDebug()<<z;
      _out << z;
      dump(blob);
      if(blob.size()==0)
      {
		qDebug() << "file empty !! not sending...";
		return;
      }
      _out << blob;
     // _outblock.append( blob);

      qDebug(">> done");

}

void SFEFileQuery::doReceive()
{
    _in >> _filename;
    qDebug("filename:");
    qDebug()<<_filename;
//    quint32 left = _size-(_filename.size()+sizeof(QString)+sizeof(quint32));


    // pour le fun on passe par un qbuffer pas obligatoire !!!
    /*QBuffer qb (&_inblock);
    qb.open(QIODevice::ReadWrite);
    qb.seek(_filename.size()+sizeof(QString)+sizeof(quint32));*/
            //>> array;
   /* QByteArray array = qb.readAll();
    dump(array);
    qDebug()<< array;*/

    QByteArray array;
    _in >> array;

    QString filepathname = _filename.prepend(_baseDir);
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
    QFile fileToSave(filepathname);
    if(!fileToSave.open(QIODevice::WriteOnly))
    {
        qDebug() << "can not open";
        qDebug() << _filename;
    }
    fileToSave.write(array);
    dump(array);
    fileToSave.close();
    //int pos, int len
}























/*
fileQuery fq(file);
protocole.send(fq);

protocole.recieve();
*/
