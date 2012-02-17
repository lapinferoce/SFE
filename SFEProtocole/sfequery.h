#ifndef SFEQUERY_H
#define SFEQUERY_H

#include <QTcpSocket>
#include "SFEProtocole_global.h"
//#include "sfenotypequery.h"

class SFENoTypeQuery;

class SFEPROTOCOLESHARED_EXPORT SFEQuery
{
public:
    enum QueryType {
                        FILE_TYPE,
                        LIST_TYPE,
			NOTYPE_TYPE,
			LS_TYPE,
			GET_TYPE,
			BIG_FILE_TYPE,
                        UNDEFINED_TYPE
    };

    SFEQuery(QueryType atype);
    void mutateFrom(SFENoTypeQuery* notype);

    void dump(QByteArray array);

    QueryType type();
    QByteArray outblock();
    QByteArray inblock();

    void Send(QTcpSocket &socket);
    void Receive(QTcpSocket &socket);

/*    void writeBlock(&QByteArray);
    QByteArray readBlock();
*/
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
