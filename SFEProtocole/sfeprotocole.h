#ifndef SFEPROTOCOLE_H
#define SFEPROTOCOLE_H

#include <QTcpSocket>

#include "sfequery.h"

#include "SFEProtocole_global.h"

class SFEPROTOCOLESHARED_EXPORT SFEProtocole {
public:
    SFEProtocole(QTcpSocket& socket);
    void Send(SFEQuery* query);
    void Receive(SFEQuery *query);
private:
    QTcpSocket& _socket;
};

#endif // SFEPROTOCOLE_H
