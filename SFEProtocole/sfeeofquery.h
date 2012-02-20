#ifndef SFEEOFQUERY_H
#define SFEEOFQUERY_H


#include <QString>
#include <QDir>
#include <QDirIterator>

#include "SFEProtocole_global.h"
#include "sfequery.h"


class SFEPROTOCOLESHARED_EXPORT SFEEOFQuery : public SFEQuery
{
public:
    SFEEOFQuery();

    void doSend();
    void doReceive();
private:

};

#endif
