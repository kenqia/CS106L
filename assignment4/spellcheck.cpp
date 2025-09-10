#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
namespace rv = std::ranges::views;

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  auto space_it = find_all(source.begin(), source.end(), [](char ch){ return std::isspace(static_cast<unsigned char>(ch)); });

  Corpus result;
  auto insert_it = std::inserter(result, result.begin());
  
  auto fun = [&source](auto begin, auto end) -> Token {
     return Token{source, begin, end};
  };
  std::transform(space_it.begin(), space_it.end() - 1, 
                 space_it.begin() + 1, 
                 insert_it, fun);

  std::erase_if(result, [](const Token& token){
                return token.content.empty();
  });

  return result;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  auto source_view = source | rv::filter([&dictionary](const Token& token){return !dictionary.contains(token.content);})
                            | rv::transform([&dictionary](const Token& token){
                                                auto d_view = dictionary | rv::filter([token](const std::string& s){return levenshtein(token.content, s) == 1;});
                                                std::set<std::string> suggestions(d_view.begin(), d_view.end());
                                                return Misspelling{token, suggestions};
                              });

  auto filtered = source_view | rv::filter([](const Misspelling& mis){return !mis.suggestions.empty();});

  auto result = std::set<Misspelling>(filtered.begin(), filtered.end());
  return result;
}

/* Helper methods */

#include "utils.cpp"