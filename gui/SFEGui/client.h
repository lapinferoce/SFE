#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QQueue>
#include "sfequery.h"
#include "sfebigfilequery.h"

class Client: public QObject
{
Q_OBJECT
public:
  Client(QObject* parent = 0);
  ~Client();
  void start(QString address, quint16 port);
  void push(SFEQuery* q);
public slots:
  void onTransfer();
  void onDisconnect();
  void onError(QAbstractSocket::SocketError err);

/*signals:
  void sendLog(QString& msg);
*/
private:
  QTcpSocket _client;
  QQueue<SFEQuery*> _queue;
};


#endif // CLIENT_H
