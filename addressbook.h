#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QMap>

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = nullptr);

private slots:
    void addContact();
    void editContact();
    void deleteContact();
    void submitContact();
    void cancel();

private:
    QLineEdit *nameArea;
    QLineEdit *mailArea;
    QLineEdit *telArea;
    QString oldName;
    QString oldMail;
    QString oldTel;
    QVector<AddressBook*> contacts;

    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;

    void tempState();
    void stableState();
};

#endif // ADDRESSBOOK_H
