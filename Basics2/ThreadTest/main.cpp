#include <QCoreApplication>
#include "mythread.h"
#include <QMutex>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int sharedCounter = 0;
    QMutex mutex;

    MyThread t1("Thread-1", sharedCounter, mutex);
    MyThread t2("Thread-2", sharedCounter, mutex);
    MyThread t3("Thread-3", sharedCounter, mutex);

    t1.start();
    t2.start();
    t3.start();

    t1.wait();
    t2.wait();
    t3.wait();

    qDebug() << "Final counter value:" << sharedCounter;

    return 0;
}
