#include "connection.h"
#include "qdebug.h"
#include <iostream>
#include <windows.h>
#include <Wininet.h>

using namespace std;

Connection::Connection()
{
    QTimer::singleShot(100, this, SLOT(isConnect()));
    timer = new QTimer();
    timer->setInterval(100000);
    connect(timer, SIGNAL(timeout()), this, SLOT(isConnect()));
    timer->start();
}
Connection::~Connection(){}

void Connection::isConnect()
{

    bool result = true;

    DWORD lpresult;
    bool winresult = InternetGetConnectedState(&lpresult,0);
    result = winresult == 1 ? true : false;

    emit checkConnection(result);

}
