#pragma once
#include <optional>
#include <string>
#include <vector>

enum class TokenType { exit, int_literal, semicolon };

struct Token {
  TokenType type;
  std::optional<std::string> value;
};

std::vector<Token> tokenize(std::string &input);
