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
      tmp.push_back(input.at(i));
      ++i;
      while (isalnum(input.at(i))) {
        tmp.push_back(input.at(i));
        ++i;
      }
      --i;
      if (tmp == "return") {
        tokenizedVec.push_back({.type = TokenType::_return});
        std::cout << tmp << std::endl;
      } else {
        std::cerr << "Bro" << std::endl;
        exit(1);
      }
      tmp.clear();
    } else if (isdigit(input.at(i))) {
      tmp.push_back(input.at(i));
      ++i;
      while (isdigit(input.at(i))) {
        tmp.push_back(input.at(i));
        ++i;
      }
      --i;
      tokenizedVec.push_back({.type = TokenType::int_literal, .value = tmp});
      std::cout << tmp << std::endl;
      tmp.clear();
    } else if (input.at(i) == ';') {
      tokenizedVec.push_back({.type = TokenType::semicolon});
      std::cout << ';' << std::endl;
    } else if (isspace(input.at(i))) {
      continue;
    } else {
      std::cerr << "Bro" << std::endl;
      exit(1);
    }
  }

  return tokenizedVec;
}
