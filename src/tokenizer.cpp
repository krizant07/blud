#include "tokenizer.h"
#include <cctype>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

std::vector<Token> tokenize(std::string &input) {
  std::vector<Token> tokenizedVec;

  std::string tmp;

  for (int i = 0; i < input.size(); ++i) {

    if (isalpha(input.at(i))) {

      do {
        tmp.push_back(input.at(i));
        ++i;
      } while (isalnum(input.at(i)));

      if (tmp == "exit")
        tokenizedVec.push_back({.type = TokenType::exit});
      else {
        std::cerr << "Bro" << std::endl;
        exit(1);
      }

      tmp.clear();
      --i;
    } else if (isdigit(input.at(i))) {

      do {
        tmp.push_back(input.at(i));
        ++i;
      } while (isdigit(input.at(i)));

      tokenizedVec.push_back({.type = TokenType::int_literal, .value = tmp});
      tmp.clear();
      --i;
    } else if (input.at(i) == ';') {
      tokenizedVec.push_back({.type = TokenType::semicolon});
    } else if (isspace(input.at(i))) {
      continue;
      std::cout << "test";
    } else {

      std::cerr << "Bro" << std::endl;
      exit(1);
    }
  }

  return tokenizedVec;
}
