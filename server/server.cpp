// server.cc
#include "server.h"
#include <QFileInfo>
#include <QDataStream>
#include <iostream>

#include "sfeprotocole.h"
#include "sfefilequery.h"
#include "sfequery.h"

using namespace std;

Server::Server(QObject* parent): QObject(parent)
{
  connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

  server.listen(QHostAddress::Any, 16065);
  dataSize = 0;
}

Server::~Server()
{
  server.close();
}

void Server::acceptConnection()
{
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}


void Server::startRead()
{
    qDebug("got reading");
    SFEQuery* query;
    query = new SFEFileQuery("./tmp/");
    SFEProtocole protocole(*client);
    protocole.Receive(query);
    delete query;
    client->close();
    qDebug(">> done");

}

#ifdef __NEW__
void Server::startRead()
{
  QDataStream stream(client);
  stream.setVersion(QDataStream::Qt_4_7);

  if (dataSize == 0)
  {
    if(client->bytesAvailable()<sizeof(quint32))
	client->waitForReadyRead(1000);
    
    stream >> dataSize;
    qDebug("got size %d",dataSize);
  }

  quint32 left = dataSize - sizeof(quint32);
  while(client->bytesAvailable()<left){
    qDebug("2 available: %d",(int)client->bytesAvailable());
     client->waitForReadyRead(1000);
  }
  quint32 type;
  stream >> type;
  qDebug("type:");
  qDebug()<<type;
  QString uu;
  stream >> uu;
  qDebug("filename:");
  qDebug()<<uu;
  left = left-(uu.size()+sizeof(QString)+sizeof(quint32));
  qDebug("reading: %d",(int)client->bytesAvailable());
  QByteArray array = client->read(left);
  
 // for (int i=0; i<array.size(); i++) {
//    qDebug("--%c",array.constData()[i]);

        std::string s = QString(array.toHex()).toStdString();

        QString formated;
        for(unsigned int i=0;i<s.length();i++)
        {
            formated+=s[i];
            if(i%2==0)
                formated+=" ";
            if(i%32==0){
                formated+="|\n";

            }
        }

        qDebug()<< "---\n"<<formated;
   //  }

  QFile fileToSave("/tmp/file");
  fileToSave.open(QIODevice::WriteOnly);
  fileToSave.write(array);
  //QDataStream out(&fileToSave);
 // #out.seek(0);
  //out << array.data();
  
  client->close();
  
    qDebug("bye");
  
}
#endif
