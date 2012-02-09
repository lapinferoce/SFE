#include "sfequery.h"

SFEQuery::SFEQuery(QueryType atype):_out(&_outblock, QIODevice::WriteOnly),_in(&_inblock, QIODevice::ReadOnly)
{
    _type = atype;

}

QueryType SFEQuery::type()
{
	return _type;
}

void SFEQuery::Send(QTcpSocket &socket)
{
    //set stream release
    _out.setVersion(QDataStream::Qt_4_7);
    //reserve place for total query size
    _out<< (quint32)0;
    //set command
    _out<< (quint32)_type;

    qDebug("cmd type %d",_type);

    doSend();

    _out.device()->seek(0);
    _out << (quint32) _outblock.size();

    qDebug("cmd size: %d",_outblock.size());


    socket.write(_outblock);
    socket.flush();


}

void SFEQuery::Receive(QTcpSocket &socket)
{
    // QDataStream _in((QTcpSocket*)&socket);

    _in.setVersion(QDataStream::Qt_4_7);


    while(socket.bytesAvailable()<sizeof(quint32))
        socket.waitForReadyRead(1000);

    qDebug("reading %d",sizeof(quint32));
    QByteArray ba = socket.peek(sizeof(quint32));
    _inblock.append(ba);

    _in >> _size;

    qDebug("cmd size: %d",_size);

   quint32 left = _size;//- sizeof(quint32);

    while(socket.bytesAvailable()<left){
        qDebug("2 available: %d",(int)socket.bytesAvailable());
        socket.waitForReadyRead(1000);
    }
    qDebug("reading: %d",left);

    QByteArray ba2 = socket.peek(left);
    _inblock.append(ba2);
    _in.skipRawData(sizeof(quint32));
    quint32 type;
    _in >> type;

    qDebug("got type: %d",type);

    if (_type!=SFEQuery::NOTYPE && type!=(quint32)_type)
        qDebug("error type !=");
    _type=(SFEQuery::QueryType)type;
    doReceive();
}
