#ifndef SFENOTYPEQUERY_H
#define SFENOTYPEQUERY_H


#include <QString>

#include "SFEProtocole_global.h"
#include "sfequery.h"

class SFEPROTOCOLESHARED_EXPORT SFENoTypeQuery : public SFEQuery
{
public:
    SFENoTypeQuery();

    void doSend();
    void doReceive();
};

#endif // SFEFILEQUERY_H
