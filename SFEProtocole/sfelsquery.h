#ifndef SFELSQUERY_H
#define SFELSQUERY_H


#include <QString>
#include <QDir>
#include <QDirIterator>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFELSQuery : public SFEQuery
{
public:
    SFELSQuery();

    void doSend();
    void doReceive();
private:

};

#endif
