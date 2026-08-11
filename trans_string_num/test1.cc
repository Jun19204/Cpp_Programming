#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Date {
private:
    unsigned year;
    unsigned month;
    unsigned day;

    // "January", "Jan" 같은 문자열을 숫자로 변환하는 헬퍼 함수
    unsigned monthStr_to_num(const std::string& monthStr) const {
        const std::vector<std::string> monthPrefixes = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        
        for (std::vector<std::string>::size_type i = 0; i < monthPrefixes.size(); ++i) {
            if (monthStr.find(monthPrefixes[i]) == 0) {
                return static_cast<unsigned> (i + 1);
            }
        }
        return 1;
    }

public:
    Date(const std::string& str) : month(monthStr_to_num(str)), day(0), year(0) {}
};





