#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QString>
#include <QStringList>

class UserInfo : public QObject
{
    Q_OBJECT
public:
    explicit UserInfo(QObject *parent = nullptr);

    QString name;
    int age = 18;
    QString favoriteColor;
    QStringList hobbies;
};

#endif // USERINFO_H
