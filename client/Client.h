// client.h
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>

class Client: public QObject
{
Q_OBJECT
public:
  Client(QObject* parent = 0);
  ~Client();
  void start(QString address, quint16 port);
public slots:
  void onTransfer();
  void onDisconnect();
  void onError(QAbstractSocket::SocketError err);
private:
  QTcpSocket client;
};














