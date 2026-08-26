#include "myproject/StrBlob.h"

#include "myproject/StrBlobPtr.h"
#include <stdexcept>

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

// const에 대해 다중정의
const std::string & // 얕은 상수성이므로 반환타입은 const가 아니어도 가능하지만
                    // '논리적 상수성'을 위해서 const로 한다.
StrBlob::front() const // this포인터를 const에 대한 this포인터로 함으로써
                       // const인 객체에서도 호출이 가능하게 한다.
{
  check(0, "front on empty StrBlob");
  return data->front();
}
// const에 대해 다중정의
const std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
