#include "addressbook.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>

AddressBook::AddressBook(QWidget *parent)
    : QWidget (parent)
{
    // Widgets
    nameArea = new QLineEdit("John Doe");
    mailArea = new QLineEdit;
    telArea = new QLineEdit;
    addButton = new QPushButton("Add ➕");
    editButton = new QPushButton("Edit 📝");
    deleteButton = new QPushButton("Delete 🗑️");
    submitButton = new QPushButton("Submit ✔️");
    cancelButton = new QPushButton("Cancel ❌");

    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *mergeSection = new QHBoxLayout;
    QFormLayout *formSection = new QFormLayout;
    QVBoxLayout *buttonSection = new QVBoxLayout;
    QVBoxLayout *footer = new QVBoxLayout;

    // Setting up layouts
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->addWidget(nameArea);
    mainLayout->addLayout(mergeSection);
    mainLayout->addLayout(footer, Qt::AlignBottom);
    mergeSection->addLayout(formSection);
    mergeSection->addLayout(buttonSection);
    formSection->addRow("Mail: ", mailArea);
    formSection->addRow("Tel: ", telArea);
    buttonSection->addWidget(editButton);
    buttonSection->addWidget(deleteButton);
    buttonSection->addWidget(submitButton);
    buttonSection->addWidget(cancelButton);
    footer->addWidget(addButton, 0, Qt::AlignBottom);

    setLayout(mainLayout);

    // States
    nameArea->setReadOnly(true);
    nameArea->setFrame(false);
    mailArea->setReadOnly(true);
    mailArea->setFrame(false);
    telArea->setReadOnly(true);
    telArea->setFrame(false);
    submitButton->hide();
    cancelButton->hide();

    currentState = Nav;

    // Signals & Slots
    connect(addButton, &QPushButton::clicked, this, &AddressBook::addContact);
    connect(editButton, &QPushButton::clicked, this, &AddressBook::editContact);
    connect(deleteButton, &QPushButton::clicked, this, &AddressBook::deleteContact);
    connect(submitButton, &QPushButton::clicked, this, &AddressBook::submitContact);
    connect(cancelButton, &QPushButton::clicked, this, &AddressBook::cancelContact);
}

void AddressBook::addContact() {
    nameArea->clear();
    mailArea->clear();
    telArea->clear();

    stateUpd(Add);
}

void AddressBook::editContact() {
    oldName = nameArea->text();
    oldMail = mailArea->text();
    oldTel = telArea->text();

    stateUpd(Edit);
}

void AddressBook::deleteContact() {
    QString name = nameArea->text();
    nameArea->clear();
    mailArea->clear();
    telArea->clear();

    contacts.remove(name);
}

void AddressBook::submitContact() {
    QString name = nameArea->text();
    QString mail = mailArea->text();
    QString tel = telArea->text();

    contacts.insert(name, mail+tel);

    stateUpd(Nav);
}

void AddressBook::cancelContact() {
    nameArea->setText(oldName);
    mailArea->setText(oldMail);
    telArea->setText(oldTel);

    stateUpd(Nav);
}

void AddressBook::stateUpd(State state) {
    currentState = state;

    switch (currentState) {
    case Add:
        nameArea->setReadOnly(false);
        nameArea->setFrame(true);
        nameArea->setFocus();
        mailArea->setReadOnly(false);
        mailArea->setFrame(true);
        telArea->setReadOnly(false);
        telArea->setFrame(true);

        editButton->hide();
        deleteButton->hide();
        submitButton->show();
        cancelButton->show();
        addButton->setEnabled(false);
    case Edit:
        nameArea->setReadOnly(false);
        nameArea->setFrame(true);
        nameArea->setFocus();
        mailArea->setReadOnly(false);
        mailArea->setFrame(true);
        telArea->setReadOnly(false);
        telArea->setFrame(true);

        editButton->hide();
        deleteButton->hide();
        submitButton->show();
        cancelButton->show();
        addButton->setEnabled(false);
    case Nav:
        nameArea->setReadOnly(true);
        nameArea->setFrame(false);
        mailArea->setReadOnly(true);
        mailArea->setFrame(false);
        telArea->setReadOnly(true);
        telArea->setFrame(false);

        editButton->show();
        deleteButton->show();
        submitButton->hide();
        cancelButton->hide();
        addButton->setEnabled(true);
    }
}
