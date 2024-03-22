#include "toAsm.h"
#include "tokenizer.h"
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  std::string content;
  if (argc == 1) {
    std::cerr << "Please input a file" << std::endl;
    return 1;
  } else if (argc > 2) {
    std::cerr << "Please only input 1 file" << std::endl;
    return 1;
  } else {
    std::stringstream content_stream;
    std::fstream input(argv[1], std::ios::in);
    content_stream << input.rdbuf();
    content = content_stream.str();
    input.close();
  }

  std::vector<Token> tokenVec = tokenize(content);

  std::fstream file("../out.asm", std::ios::out);
  file << tokensToAsm(tokenVec);
  file.close();

  system("nasm -felf64 ../out.asm");
  system("ld -o out ../out.o");
}
