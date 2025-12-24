#pragma once
#include <QThread>
#include <QMutex>

class MyThread : public QThread {
public:
    MyThread(const QString& name, int& counter, QMutex& mutex);

protected:
    void run() override;

private:
    QString name;
    int& sharedCounter; // we don't create shraredCounter member every time we create an object of MyThread.
                        // We just give it to the referance of the variable created in main.cpp
                        // Her MyThread objesi oluşturduğumuzda yeniden bir sharedCounter oluşturmuyoruz bunun yerine
                        // main.cpp de oluşturulan sharedCounter değişkeninin referansını veriyoruz.
    QMutex& mutex;      // Same here.
                        // Aynı durum burada da geçerli.
};
