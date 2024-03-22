#include "toAsm.h"
#include <sstream>
#include <string>
#include <vector>

std::string tokensToAsm(std::vector<Token> &tokens) {
  std::stringstream output;
  output << "global _start\n_start:\n";

  for (int i = 0; i < tokens.size(); ++i) {
    if (tokens.at(i).type == TokenType::_return) {
      if (tokens.at(i + 1).type == TokenType::int_literal) {
        if (tokens.at(i + 2).type == TokenType::semicolon) {
          output << "    mov rax, 60\n";
          output << "    mov rdi, " << tokens.at(i + 1).value.value() << "\n";
          output << "    syscall";
        }
      }
    }
  }
  return output.str();
}
