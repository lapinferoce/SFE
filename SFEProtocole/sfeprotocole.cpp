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
			qDebug() << "Failed!! file not found" << filepathname;
		}                                         	
		
		while(!fileToSend.atEnd())
		{
			QByteArray chunkBlob = fileToSend.read(50000); //50ko
			SFEBigFileChunkQuery* chunk= new SFEBigFileChunkQuery(chunkBlob);
			chunk->Send(_socket);
			delete chunk;
			qDebug() << "sending " << chunkBlob.size();
		}	
		fileToSend.close();
		SFEEOFQuery* eof=new SFEEOFQuery();
		eof->Send(_socket);
		delete eof;	
	}

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

	if(rec->type()==SFEQuery::BIG_FILE_TYPE)
	{
		ret = (SFEQuery*) new SFEBigFileQuery("./tmp/");
		ret->mutateFrom(rec);
	
		QString filepathname = ((SFEBigFileQuery*)ret)->filename();
		qDebug()<< "filename "<< filepathname;
		QFile file(filepathname);
		
			
	       
		if (!file.open(QIODevice::WriteOnly))
		{
			qDebug()<< "can not open" << filepathname ;
		}
		SFENoTypeQuery* q = new SFENoTypeQuery();
		qDebug() << "recv";
        	q->Receive(_socket);
        	qDebug() << "ecv done";
		while(q->type()==SFEQuery::BIG_FILE_CHUNK_TYPE)
		{	
			if(q->type()==SFEQuery::BIG_FILE_CHUNK_TYPE)
			{
				SFEBigFileChunkQuery* bcfq=new SFEBigFileChunkQuery();
				qDebug("alive");
				bcfq->mutateFrom(q);
				qDebug() << "#" ; 
				file.write(bcfq->blob());
				qDebug() << "wrote";
				delete q;
				delete bcfq;
				q = new SFENoTypeQuery();
				qDebug() << "recv";
				q->Receive(_socket);
				qDebug() << "ecv done";
			}
		}
		if(q->type()==SFEQuery::EOF_TYPE)
		{
			SFEEOFQuery* eof=new SFEEOFQuery();
			eof->mutateFrom(q);	 
		file.close();
		}
		return ret;                                    	
	}

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
