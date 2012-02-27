#include "client.h"
#include <QHostAddress>
#include <QFileInfo>
#include <QDataStream>
#include <iostream>

#include "sfeprotocole.h"
#include "sfefilequery.h"
#include "sfefilelistquery.h"
#include "sfequery.h"

using namespace std;

Client::Client(QObject* parent): QObject(parent)
{
  connect(&_client, SIGNAL(connected()),
    this, SLOT(onTransfer()));
  connect(&_client,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
  connect(&_client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
  _client.close();
}

void Client::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  _client.connectToHost(addr, port);
}
void Client::onDisconnect()
{
    qDebug("disconected !!");
}

void Client::onError(QAbstractSocket::SocketError errno)
{
    _client.close();

}
void Client::push(SFEQuery* q)
{
    _queue.enqueue(q);
}

void Client::onTransfer()
{
    SFEProtocole protocole(_client);

    while (!_queue.isEmpty())
    {
             SFEQuery *q = _queue.dequeue();
             protocole.Send(q);
             delete q;
    }


     //SFEQuery* listFile;
    //listFile = new SFEFileListQuery("./tmp","./tmp");


    /*    SFEQuery* listFile;
    SFEQuery* listFile2;
    SFEQuery* query;
    query = new SFEBigFileQuery("./tmp/toto","./tmp/");

    listFile = new SFEFileListQuery("./tmp","./tmp");
    listFile2 = new SFEGetQuery("./tmp/toto");
    SFEProtocole protocole(client);
//
      protocole.Send(listFile2);
      protocole.Send(query);
      protocole.Send(listFile);
    //protocole.Send(query);


    qDebug(">> done");*/
}
