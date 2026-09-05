#include "Query/NotQuery.h"
#include "Query/Query.h"
#include "Query/TextQuery.h"
#include "Query/QueryResult.h"
#include <cstddef>
#include <memory>
#include <set>

QueryResult
NotQuery::eval(const TextQuery& text) const {
  auto result = query_.eval(text);
  auto ret_lines = std::make_shared<std::set<LineNo>>();
  auto beg = result.begin();
  auto end = result.end();
  auto size = result.getFile()->size();
  for (std::size_t n = 0; n != size; ++n) {
    if (beg == end || *beg != n) {
      ret_lines->insert(n);
    }
    else if (beg != end) {
      ++beg;
    }
  }
  return QueryResult(rep(), ret_lines, result.getFile());
}
