#include "StrVec.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <utility>

using namespace std;

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    allocator_traits<decltype(alloc)>::construct(alloc, first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(static_cast<size_t>(e-b));
    return make_pair(data, uninitialized_copy(b, e, data));
}

void StrVec::free()
{
    if (elements) {
        for_each(
                make_reverse_iterator(first_free), 
                make_reverse_iterator(elements), 
                [](const string &s) {
                    allocator_traits<decltype(alloc)>::destroy(alloc, addressof(s));
                }
        ); 
        alloc.deallocate(elements, static_cast<size_t>(cap - elements));
    }
}

// 복사 제어 - 복사 생성자
StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 복사 제어 - 복사 대입 연산자
StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

// 복사 제어 - 소멸자
StrVec::~StrVec()
{
    free();
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    
    auto dest = newdata;
    auto elem = elements;
    
    for (size_t i = 0; i != size(); ++i) {
        allocator_traits<decltype(alloc)>::construct(alloc, dest++, std::move(*elem++));
    }
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}















