#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Mini Application");

    QLabel *label = new QLabel("<h2>Heading</h2> <b>Hello</b> <i>world!</i>");
    label->show();

    QPushButton *button1 = new QPushButton("one");
    QPushButton *button2 = new QPushButton("two");
    QPushButton *button3 = new QPushButton("three");

    //QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vlayout = new QVBoxLayout;

    vlayout->addWidget(label);
    vlayout->addWidget(button1);
    vlayout->addWidget(button2);
    vlayout->addWidget(button3);

    window->setLayout(vlayout);
    window->show();

    QWidget *window2 = new QWidget;
    window2->setWindowTitle("Mini Application");

    QLabel *label2 = new QLabel("Name:");
    QLineEdit *edit = new QLineEdit;
    QPushButton *button4 = new QPushButton("OK");

    QGridLayout *gridlayout = new QGridLayout;

    gridlayout->addWidget(label2, 0, 0);
    gridlayout->addWidget(edit, 0, 1);
    gridlayout->addWidget(button4, 1, 0, 1, 2);

    window2->setLayout(gridlayout);
    window2->show();


    return app.exec();  // starts the loop
}
