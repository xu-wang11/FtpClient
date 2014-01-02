#ifndef PARSELIST_H
#define PARSELIST_H
#include <QString>
#include "qurlinfo.h"

void _q_fixupDateTime(QDateTime *dateTime);
 void _q_parseUnixDir(const QStringList &tokens, const QString &userName, QUrlInfo *info);
 void _q_parseDosDir(const QStringList &tokens, const QString &userName, QUrlInfo *info);
 bool parseDir(const QByteArray &buffer, const QString &userName, QUrlInfo *info);
#endif // PARSELIST_H
