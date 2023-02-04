#ifndef CONNECTION_H
#define CONNECTION_H

#include <QTimer>
#include <QObject>

#include "singleton.h"

class Connection : public QObject
{
    Q_OBJECT

public:
    Connection();
    ~Connection();

    QTimer *timer;

public slots:
    void isConnect();

signals:
    void checkConnection(bool result);

private:
    friend class Singleton<Connection>;
};

#define CONNECTION Singleton<Connection>::instance()

#endif // CONNECTION_H


