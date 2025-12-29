#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

void readResourceFile(const QString& resourcePath)
{
    QFile file(resourcePath);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Resource read error:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    qDebug() << "Resource content:\n" << in.readAll();

    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Trying to read resource file...";

    // Resource içinden okuma
    // Read from resource
    readResourceFile(":/new/prefix1/example.txt");

    return 0;
}
