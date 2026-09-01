#include "Query/Query.h"

#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

StrVec sv;

TextQuery::TextQuery(ifstream &is) : file(make_shared<StrVec>()) {
  string text;
  while (getline(is, text)) {
    file->push_back(text);        // 본문 내용 기억
    line_no n = file->size() - 1; // 현재 줄 번호
    istringstream line(text);

    string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines) {
        lines = make_shared<set<line_no>>();
      }
      lines->insert(n);
    }
  }
}

auto TextQuery::query(const string &sought) const -> QueryResult {
  static shared_ptr<set<line_no>> nodata = make_shared<set<line_no>>();
  auto loc = wm.find(sought);
  if (loc == wm.cend())
    return QueryResult{sought, nodata, file};
  else
    return QueryResult{sought, loc->second, file};
}

inline auto 
make_plural(size_t sz, const string &word, const string &ending) -> string {
  return (sz > 1) ? word + ending : word;
}

auto print(ostream &os, const QueryResult &qr) -> ostream&
{
  os << "\'" << qr.sought << "\'" << " occurs " << qr.lines->size() << " "
     << make_plural(qr.lines->size(), "time", "s") << '\n';
  for (auto num : *qr.lines) {
    os << "\t(line " << num + 1 << ") "
       << *(qr.file->begin() + static_cast<long>(num)) << '\n';
  }
  return os;
}

void runQueries(ifstream &infile) {
  TextQuery tq(infile);
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, tq.query(s)) << '\n';
  }
}
