#include <cstdlib>
#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string adress;
    const std::string& getName() const
    { return name; }
    const std::string& getAdress() const
    { return adress; }
};

// 인터페이스인 비멤버 함수
std::istream &read(std::istream &is, Person &man)
{
    // EOF등과 같은 입력 실패를 대비해 객체 초기화하기
    man.name.clear();
    man.adress.clear();

    // 문장을 입력 받으므로 만약을 대비해 버퍼 청소하기(단어 입력은 안해줘도 됨)
    while (is && std::isspace(is.peek())) { is.ignore(); }

    // 만약 여기서 실패했더라도 객체는 빈상태가 보장됨
    std::getline(is, man.name);
    std::getline(is, man.adress);
    return is;
}

// 인터페이스인 비멤버 함수
std::ostream &print(std::ostream &os, Person &man)
{
    os << man.name << " : " << man.adress;
    return os;
}

int main()
{
    Person person;
    std::cout << "입력" << std::endl;
    read(std::cin, person);
    print(std::cout, person);

    return EXIT_SUCCESS;
}
