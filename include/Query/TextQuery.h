#pragma once

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult;

class TextQuery {
public:
  using LineNo = std::vector<std::string>::size_type;
  TextQuery(std::ifstream&);
  [[nodiscard]]
  QueryResult query(const std::string&) const;

private:
  std::shared_ptr<std::vector<std::string>> file; // 입력 파일
  // 단어가 나온 라인을 담고 있는 set에 각 단어를 사상한 map
  std::map<std::string, std::shared_ptr<std::set<LineNo>>> word_map;
};


void runQueries(std::ifstream &infile);


