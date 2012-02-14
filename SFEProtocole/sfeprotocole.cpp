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
	SFENoTypeQuery* rec = new SFENoTypeQuery();
	SFEQuery* ret;
	Receive(rec);
	if(rec->type()==SFEQuery::FILE_TYPE)
	{
		ret = (SFEQuery*) new SFEFileQuery("./tmp/");
		ret->mutateFrom(rec);
	}
	//ret->doReceive();
	delete rec;
	return ret;	
}
