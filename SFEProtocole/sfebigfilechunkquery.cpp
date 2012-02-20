#include "sfebigfilechunkquery.h"
#include <QBuffer>
#include <QDir>
/*SFEBigFileChunkQuery::SFEFileQuery(QFile file):SFEQuery(SFEQuery::FILE),_file(file)
{

}*/
SFEBigFileChunkQuery::SFEBigFileChunkQuery():SFEQuery(SFEQuery::BIG_FILE_CHUNK_TYPE)
{
}
SFEBigFileChunkQuery::SFEBigFileChunkQuery(QByteArray blob):SFEQuery(SFEQuery::BIG_FILE_CHUNK_TYPE)
{
    _blob = blob;
}
// size type filepath data
void SFEBigFileChunkQuery::doSend()
{

      dump(_blob);
      if(_blob.size()==0)
      {
		qDebug() << "file empty !! not sending...";
		return;
      }
      _out << _blob;

      qDebug(">> done");

}

QByteArray SFEBigFileChunkQuery::blob(){
	return _blob;
}

void SFEBigFileChunkQuery::doReceive()
{

    _in >> _blob;
    dump(_blob);

}























/*
fileQuery fq(file);
protocole.send(fq);

protocole.recieve();
*/
