#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

// A function for writing to a file
// Dosyaya yazma
void writeFile(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Write error:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << "Hello Qt File System!\n";
    out << "This file is created by QFile and QTextStream.\n";

    file.close();
    qDebug() << "File written:" << filePath;
}

// a function for reading a file
// Dosyadan okuma
void readFile(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Read error:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    qDebug() << "File content:\n" << in.readAll();

    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir baseDir(QDir::currentPath()); // the directory of the runnable program

    if (!baseDir.exists("Example")) {
        baseDir.mkdir("Example");
        qDebug() << "Example folder created";
    }

    QString filePath = baseDir.filePath("Example/example.txt");

    writeFile(filePath);
    readFile(filePath);

    return 0;
}
