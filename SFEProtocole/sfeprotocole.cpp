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
