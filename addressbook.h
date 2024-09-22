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
    void cancelContact();

private:
    QLineEdit *nameArea;
    QLineEdit *mailArea;
    QLineEdit *telArea;
    QString oldName;
    QString oldMail;
    QString oldTel;
    QMap<QString, QString> contacts;

    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;

    enum State { Nav, Add, Edit } currentState;
    void stateUpd(State state);
};

#endif // ADDRESSBOOK_H
