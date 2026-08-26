#pragma once

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
public:
  StrVec() = default;                      // 기본 생성자
  StrVec(const StrVec &);                  // 복사 생성자
  StrVec(StrVec &&) noexcept;              // 이동 생성자
  StrVec &operator=(const StrVec &) &;     // 복사 대입 연산자
  StrVec &operator=(StrVec &&) & noexcept; // 이동 대입 연산자
  ~StrVec();                               // 소멸자
  
  StrVec &operator=(std::initializer_list<std::string>);
  std::string& operator[](std::size_t n)
  { return elements[n]; }
  const std::string& operator[](std::size_t n) const
  { return elements[n]; }

  using size_type = std::size_t;

  void push_back(const std::string &);
  void push_back(std::string &&);

  std::size_t size() const 
  { return static_cast<std::size_t>(first_free - elements); }
  std::size_t capacity() const 
  { return static_cast<std::size_t>(cap - elements); }
  std::string *begin() const 
  { return elements; }
  std::string *end() const 
  { return first_free; }

private:
  inline static std::allocator<std::string> alloc;

  void chk_n_alloc() 
  {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();

  std::string *elements{nullptr};
  std::string *first_free{nullptr};
  std::string *cap{nullptr};
};
