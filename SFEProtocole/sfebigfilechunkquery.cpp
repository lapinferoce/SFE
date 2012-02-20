#include "sfebigfilechunkquery.h"
#include <QBuffer>
#include <QDir>
/*SFEBigFileChunkQuery::SFEFileQuery(QFile file):SFEQuery(SFEQuery::FILE),_file(file)
{

}*/
SFEBigFileChunkQuery::SFEFileQuery():SFEQuery(SFEQuery::BIG_FILE_CHUNK)
{
}
SFEBigFileChunkQuery::SFEFileQuery(QByteArray blob):SFEQuery(SFEQuery::BIG_FILE_CHUNK)
{
    _blob = blob;
}
// size type filepath data
void SFEBigFileChunkQuery::doSend()
{

      dump(blob);
      if(blob.size()==0)
      {
		qDebug() << "file empty !! not sending...";
		return;
      }
      _out << blob;

      qDebug(">> done");

}

QByteArray SFEBigFileChunkQuery::blob(){
	return _blob
}

void SFEBigFileChunkQuery::doReceive()
{

    _in >> blob;
    dump(blob);

}























/*
fileQuery fq(file);
protocole.send(fq);

protocole.recieve();
*/
