#ifndef SFEBIGFILECHUNKQUERY_H
#define SFEBIGFILECHUNKQUERY_H


#include <QString>
#include <QFile>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFEBigFileChunkQuery : public SFEBigFileChunkQuery
{
public:
    SFEBigFileChunkQuery();
    SFEBigFileChunkQuery(QByteArray baseDir);

    QByteArray blob();

    void doSend();
    void doReceive();
private:
    QByteArray _blob;
  //  QFile& _file;

};

#endif // SFEBIGFILECHUNKQUERY_H
