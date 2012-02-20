#include "sfeeofquery.h"
#include <QBuffer>
#include <QMutableListIterator>

SFEEOFQuery::SFEEOFQuery():SFEQuery(SFEQuery::EOF_TYPE)
{
}

// size type filepath data
void SFEEOFQuery::doSend()
{
  qDebug() << "eof";
}

void SFEEOFQuery::doReceive()
{
}


