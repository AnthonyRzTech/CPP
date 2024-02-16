#include <stdint.h>
#include <string>

typedef struct Data {
  std::string name;
  size_t age;
  Data *next;
} Data;

class Serializer {
private:
  Serializer();
  Serializer(Serializer const &other);
  Serializer &operator=(Serializer const &other);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
