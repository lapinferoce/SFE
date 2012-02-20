#include "sfeprotocole.h"
#include <QDebug>

SFEProtocole::SFEProtocole(QTcpSocket& socket):_socket(socket)
{

}

void SFEProtocole::Send(SFEQuery *query)
{
    query->Send(_socket);
    if(query->type()==SFEQuery::BIG_FILE_TYPE)
	{
		QString filepathname = ((SFEBigFileQuery*)query)->filename();
		QFile fileToSend(filepathname);

		if (!fileToSend.open(QIODevice::ReadOnly))
		{
			qDebug("Failed!! file not found");
		}                                         	

		while(!fileToSend.atEnd())
		{
			QByteArray chunkBlob = fileToSend.read(50000); //50ko
			SFEBigFileChunkQuery* chunk= new SFEBigFileChunkQuery(chunkBlob);
			chunk->send(_socket);
			delete chunk;
		}	
		fileToSend.close();
	}

}

void SFEProtocole::Receive(SFEQuery *query)
{
    query->Receive(_socket);

    if(query->type()==SFEQuery::BIG_FILE_TYPE)
	{
	
		QString filepathname = ((SFEBigFileQuery*)query)->filename();
		QFile fileToSend(filepathname);
		SFEQuery* q = new SFEQuery();
		
	   
	if (!fileToSend.open(QIODevice::WriteOnly))
	{
		qDebug()<< "can not open" << filepathname ;
	}
		do{
			q->Receive(_socket);
			if(q->type()==SFEQuery::BIG_FILE_CHUNCK_TYPE){
				fileToSend.write((SFEBigFileQuery*)q->blob);
				delete q;
				q = new SFEQuery();
			}
			qDebug("Failed!! file not found");
		} while(q->type()==SFEQuery::BIG_FILE_CHUNCK_TYPE);
		query=q;                                     	
	}
}
SFEQuery*  SFEProtocole::Receive()
{
	SFENoTypeQuery* rec = new SFENoTypeQuery();
	SFEQuery* ret;
	Receive(rec);
	if(rec->type()==SFEQuery::FILE_TYPE)
	{
		ret = (SFEQuery*) new SFEFileQuery("./tmp/");
	}
	else if(rec->type()==SFEQuery::LIST_TYPE)
	{
		ret = (SFEQuery*) new SFEFileListQuery("./tmp/");
	}
	else if(rec->type()==SFEQuery::GET_TYPE)
	{
		ret = (SFEQuery*) new SFEGetQuery();
	}
	else if(rec->type()==SFEQuery::LS_TYPE)
	{
		ret = (SFEQuery*) new SFELSQuery();
	}
	ret->mutateFrom(rec);
	//ret->doReceive();
	delete rec;
	return ret;	
}
