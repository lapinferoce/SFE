#include "sfeprotocole.h"
#include <QDebug>

SFEProtocole::SFEProtocole(QTcpSocket& socket):_socket(socket)
{

}

void SFEProtocole::Send(SFEQuery *query)
{
    query->Send(_socket);

}

void SFEProtocole::Receive(SFEQuery *query)
{
    query->Receive(_socket);

}
SFEQuery*  SFEProtocole::Receive()
{
	SFEQuery* rec = new SFENoTypeQuery();
	SFEQuery* ret = 0;
	Receive(rec);
	if(rec->type()==SFEQuery::FILE)
		ret = new SFEFileQuery(rec);
	ret->doReceive();
	return ret;	
}
