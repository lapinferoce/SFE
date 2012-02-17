#include "sfegetquery.h"
#include <QBuffer>
#include <QMutableListIterator>

SFEGetQuery::SFEGetQuery():SFEQuery(SFEQuery::GET_TYPE)
{
    _filename = "";
}
SFEGetQuery::SFEGetQuery(QString filename):SFEQuery(SFEQuery::GET_TYPE)
{
    _filename = filename;
}

QString SFEGetQuery::filename()
{
	return _filename;
}
// size type filepath data
void SFEGetQuery::doSend()
{
  _out << _filename;
  qDebug() << "trying to get:" << _filename;
}

void SFEGetQuery::doReceive()
{
    _in >> _filename;
}







/*
fileQuery fq(file);
protocole.send(fq);

protocole.recieve();
*/
