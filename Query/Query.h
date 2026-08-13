#pragma once

#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file; // 입력 파일
    // 단어가 나온 라인을 담고 있는 set에 각 단어를 사상한 map
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};


class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


void runQueries(std::ifstream &);


