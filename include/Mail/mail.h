#pragma once

#include <set>
#include <string>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs) noexcept;
    friend void swap(Folder &lhs, Folder &rhs) noexcept;

public:
    explicit Message(const std::string &&str = "") 
        : contents(str) {}

    // --- Rule of Three ---
    Message(const Message &m);            // 복사 생성자
    auto operator=(const Message &rhs) -> Message&; // 복사 대입 연산자
    ~Message();                           // 소멸자

    // 메시지-폴더 저장 및 제거 인터페이스
    void save(Folder &f);
    void remove(Folder &f);

private:
    std::string contents;
    std::set<Folder*> folders;

    // 헬퍼 함수
    void add_to_Folders(const Message &m);
    void remove_from_Folders();
};


class Folder {
    friend class Message;
    friend void swap(Folder &lhs, Folder &rhs) noexcept;

public:
    Folder() = default;

    // --- Rule of Three ---
    Folder(const Folder &f);            // 복사 생성자
    auto operator=(const Folder &rhs) -> Folder&; // 복사 대입 연산자
    ~Folder();                          // 소멸자

    // Message 포인터는 non-const이어야 서로의 상태를 변경할 수 있음
    void addMsg(Message *m) { msgs.insert(m); }
    void rmMsg(Message *m) { msgs.erase(m); }

private:
    std::set<Message*> msgs;

    // 헬퍼 함수
    void add_to_Messages(const Folder &f);
    void remove_from_Messages();
};
