#ifndef SFENOTYPEQUERY_H
#define SFENOTYPEQUERY_H


#include <QString>

#include "SFEProtocole_global.h"
#include "sfequery.h"
#include "sfenotypequery.h"

class SFEPROTOCOLESHARED_EXPORT SFENoTypeQuery : public SFEQuery
{
public:
    SFENoTypeQuery();
//    SFENoTypeQuery(QFile file);
    SFENoTypeQuery(QString filename,QString baseDir);
    SFENoTypeQuery(QString baseDir);

    void doSend();
    void doReceive();
};

#endif // SFEFILEQUERY_H
