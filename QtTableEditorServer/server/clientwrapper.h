#pragma once

#include <QObject>

#include "../socket/socketadapter.h"

class StudentDatabase;

class ThreadableClientWrapper : public QObject
{
    Q_OBJECT
public:
    explicit ThreadableClientWrapper(qintptr socketDescriptor, QObject *parent = 0);
    ~ThreadableClientWrapper();

signals:
    void finished();
    void clientConnected(QString clientAddress);

public slots:
    void run();
    void stop();

private:
    qintptr socketDescriptor;
    TcpSocketAdapter* socket;

    StudentDatabase* database;
};
