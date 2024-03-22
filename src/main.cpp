#include "tokenizer.h"
#include <fstream>
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
}
