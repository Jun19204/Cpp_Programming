#include "myproject/mail.h"

using namespace std;

// -------------------------------------
// Message 클래스 구현
// -------------------------------------

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.rmMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders) {
        f->rmMsg(this);
    }
    folders.clear();
}

Message::Message(const Message &m) 
    : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders) {
        f->rmMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->rmMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->addMsg(&rhs);
    }
}


// -----------------------------------
// Folder 클래스 구현
// -----------------------------------

void Folder::add_to_Messages(const Folder &f)
{
    for (auto it = f.msgs.begin();
                       it != f.msgs.end(); ++it) {
        (*it)->save(*this);
    }
}

void Folder::remove_from_Messages() {
    while (!msgs.empty()) {
        (*msgs.begin())->remove(*this);
    }
}

Folder::Folder(const Folder &f) {
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &rhs) {
    if (this != &rhs) {
        remove_from_Messages();
        add_to_Messages(rhs);
    }
    return *this;
}

Folder::~Folder() {
    remove_from_Messages();
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    for (auto it = lhs.msgs.begin(); it != lhs.msgs.end(); ++it) {
        (*it)->folders.erase(&lhs);
    }
    for (auto it = rhs.msgs.begin(); it != rhs.msgs.end(); ++it) {
        (*it)->folders.erase(&rhs);
    }

    swap(lhs.msgs, rhs.msgs);

    for (auto it = lhs.msgs.begin(); it != lhs.msgs.end(); ++it) {
        (*it)->folders.insert(&lhs);
    }
    for (auto it = rhs.msgs.begin(); it != rhs.msgs.end(); ++it) {
        (*it)->folders.insert(&rhs);
    }
}



