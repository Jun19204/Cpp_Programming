#include "Query/TextQuery.h"
#include "Query/QueryResult.h"

#include <cstddef>
#include <iostream>
#include <fstream>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <vector>
#include <string>

using std::size_t;
using std::vector;
using std::string;
using std::set;
using std::cout;
using std::cin;
using std::getline;
using std::ifstream;
using std::ostream;
using std::istringstream;
using std::shared_ptr;
using std::make_shared;

TextQuery::TextQuery(ifstream &istrm)
  : file(new vector<string>) {
  string text;
  while (getline(istrm, text)) {
    file->push_back(text);
    LineNo number = file->size() - 1;
    istringstream line(text);
    string word;
    while (line >> word) {
      auto& lines = word_map[word];
      if (!lines) { 
        lines = make_shared<set<LineNo>>(); 
      }
      lines->insert(number);
    }
  }
}

[[nodiscard]]
QueryResult
TextQuery::query(const string &sought) const {
  static shared_ptr<set<LineNo>> nodata = make_shared<set<LineNo>>();
  auto location = word_map.find(sought);
  if (location == word_map.end()) {
    return QueryResult(sought, nodata, file);
  }
  return QueryResult(sought, location->second, file);
}

string
makePlural(size_t size, string&& word, string&& plural) {
  return (size>1) ? word+plural : word;
}

ostream&
print(ostream& ostrm, const QueryResult& result) {
  ostrm << result.sought_ << " occurs " 
        << result.lines_->size() << " "
        << makePlural(result.lines_->size(), "time", "s") << '\n';
  for (auto num : *result.lines_) {
    ostrm << "\t(line " << num + 1 << ") "
          << *(result.file_->begin() + static_cast<long>(num)) << '\n';
  }
  return ostrm;
}

void 
runQueries(std::ifstream &infile) {
  TextQuery text_query(infile);
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string str;
    if (!(cin >> str) || str == "q") { break; }
    print(cout, text_query.query(str)) << '\n';
  }
}
