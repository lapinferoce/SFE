#include "Client.h"
#include <QHostAddress>
#include <QFileInfo>
#include <QDataStream>
#include <iostream>

#include "sfeprotocole.h"
#include "sfefilequery.h"
#include "sfequery.h"

using namespace std;
 
Client::Client(QObject* parent): QObject(parent)
{
  connect(&client, SIGNAL(connected()),
    this, SLOT(onTransfer()));
  connect(&client,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
  connect(&client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
  client.close();
}

void Client::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}
void Client::onDisconnect()
{
    qDebug("disconected !!");
}

void Client::onError(QAbstractSocket::SocketError errno)
{
    //cout <<"err:"<< client.errorString().toAscii() <<endl;
    client.close();
    //"<< (int)errno<<"
    //cout<< endl << " -- Error  on Client side :" << endl<< "\t"
    // cout<< client.errorString().toAscii();
    //center(rr << err
}

void Client::onTransfer()
{
    SFEQuery* query;
    query = new SFEFileQuery("./test","./");
    SFEProtocole protocole(client);
    protocole.Send(query);
    delete query;
    qDebug(">> done");
/*
  QString filename("./test");
  
  QString msg = ">>";
  QFile fileToSend(filename);
  
  if (!fileToSend.open(QIODevice::ReadOnly)) 
  {      
        qDebug("Failed!! file not found");
  }
  

  QByteArray blob = fileToSend.readAll();
  
  QByteArray block;
  QDataStream out (&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_7);
  out<< (quint32)0;
  qDebug(">> %d",blob.size());
  block.append( blob);

  out.device()->seek(0);
  out << (quint32) block.size();
  client.write(block);
  client.flush();*/

//  client.disconnectFromHost();
//  client.waitForDisconnected();
}
