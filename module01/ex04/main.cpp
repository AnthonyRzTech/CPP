#include "StringReplacer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
  }
  if (std::string(argv[2]).empty() || std::string(argv[3]).empty()) {
    std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  std::string outputFilename = filename + ".replace";

  std::ifstream inputFile(filename.c_str());
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return 1;
  }

  std::ofstream outputFile(outputFilename.c_str());
  if (!outputFile.is_open()) {
    std::cerr << "Error creating file: " << outputFilename << std::endl;
    inputFile.close();
    return 1;
  }

  std::stringstream buffer;
  buffer << inputFile.rdbuf();
  std::string content = buffer.str();
  std::string replacedContent =
      StringReplacer::replaceString(content, argv[2], argv[3]);

  outputFile << replacedContent;

  inputFile.close();
  outputFile.close();

  return 0;
}
