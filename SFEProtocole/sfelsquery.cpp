#include "sfelsquery.h"
#include <QBuffer>
#include <QMutableListIterator>

SFELSQuery::SFELSQuery():SFEQuery(SFEQuery::LS_TYPE)
{
}

// size type filepath data
void SFELSQuery::doSend()
{
  qDebug() << "ls";
}

void SFELSQuery::doReceive()
{
}


