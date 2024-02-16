#ifndef STRINGREPLACER_HPP
#define STRINGREPLACER_HPP

#include <string>

class StringReplacer {
public:
  static std::string replaceString(const std::string &source,
                                   const std::string &s1,
                                   const std::string &s2);
};

#endif
