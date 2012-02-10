#include "sfenotypequery.h"

SFENoTypeQuery::SFENoTypeQuery():SFEQuery(SFEQuery::FILE)
{

}
//    SFENoTypeQuery(QFile file);
SFENoTypeQuery::SFENoTypeQuery(QString filename,QString baseDir):SFEQuery(SFEQuery::FILE)
{

}
SFENoTypeQuery::SFENoTypeQuery(QString baseDir):SFEQuery(SFEQuery::FILE)
{

}

void SFENoTypeQuery::doSend()
{
}
void SFENoTypeQuery::doReceive()
{
}
