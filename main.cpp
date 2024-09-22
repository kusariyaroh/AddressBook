#include "addressbook.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AddressBook address_book;
    address_book.setWindowTitle("ADDRESS BOOK");
    address_book.setFixedSize(300, 700);
    address_book.show();

    return app.exec();
}
