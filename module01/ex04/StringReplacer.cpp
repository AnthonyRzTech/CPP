#include "StringReplacer.hpp"

std::string StringReplacer::replaceString(const std::string &source,
                                          const std::string &s1,
                                          const std::string &s2) {
  std::string result;
  size_t pos = 0;
  size_t s1Len = s1.length();
  size_t lastPos = 0;

  while ((pos = source.find(s1, lastPos)) != std::string::npos) {
    result += source.substr(lastPos, pos - lastPos) + s2;
    lastPos = pos + s1Len;
  }
  result += source.substr(lastPos);
  return result;
}
