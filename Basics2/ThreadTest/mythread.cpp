#include "mythread.h"
#include <QDebug>

MyThread::MyThread(const QString& name, int& counter, QMutex& mutex)
    : name(name), sharedCounter(counter), mutex(mutex)
{}

void MyThread::run() {
    for(int i = 0; i < 100; i++) {
        mutex.lock();               // before changed a value which is shared we need to lock the mutex
                                    // to prevent accessing at the same time
                                    // diğer thread veya programlarla paylaşılan bir değere erişmeden önce
                                    // mutex'i kilitleriz. Aynı anda erişimi önlemek için
        sharedCounter++;
        qDebug() << "counter =" << sharedCounter << "changed by" << this->name;
        mutex.unlock();

        QThread::msleep(1);
    }
}
