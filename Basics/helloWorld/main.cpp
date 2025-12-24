#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "Hello World :)";

    qDebug () << "Hello World!";
    qDebug () << str;

    return a.exec();  // program doesn't terminate here, enters to the event loop
                      // in event loop it stays runnning and waits for signals, timers, user inputs, ...
                      // program bu satırda bitmez. Olay döngüsüne girer.
                      // olay döngüsündeki program zamanlayıcı, sinyal, kullanıcı girdisi gibi şeyleri dinlemeye devam eder.
}
