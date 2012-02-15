#ifndef SFEPROTOCOLE_GLOBAL_H
#define SFEPROTOCOLE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SFEPROTOCOLE_LIBRARY)
#  define SFEPROTOCOLESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SFEPROTOCOLESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SFEPROTOCOLE_GLOBAL_H