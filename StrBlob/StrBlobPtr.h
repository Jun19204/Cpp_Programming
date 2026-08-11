#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class StrBlob;

class StrBlobPtr {
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &a, std::size_t sz = 0);
    std::string& deref() const;
    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
