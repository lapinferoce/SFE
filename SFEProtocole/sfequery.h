#ifndef SFEQUERY_H
#define SFEQUERY_H

#include <QTcpSocket>

#include "SFEProtocole_global.h"

class SFEPROTOCOLESHARED_EXPORT SFEQuery
{
public:
    enum QueryType {
                        FILE,
                        LIST,
                        UNDEFINED
    };

    SFEQuery(QueryType atype);

    void Send(QTcpSocket &socket);
    void Receive(QTcpSocket &socket);

    virtual void doSend() = 0;
    virtual void doReceive() = 0;

private:
   QueryType    _type;
protected:
   QByteArray   _outblock;
   QDataStream  _out;
   QByteArray   _inblock;
   QDataStream  _in;
   quint32      _size;

};

#endif // SFEQUERY_H
