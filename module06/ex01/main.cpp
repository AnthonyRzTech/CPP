#include "Serializer.hpp"
#include <iostream>

int main() {
  // Création et initialisation d'une instance de Data
  Data myData = {"Grimoire", 42, NULL};
  std::cout << "Original Data: Name = " << myData.name
            << ", Age = " << myData.age << std::endl;

  // Sérialisation de l'instance de Data
  uintptr_t serialized = Serializer::serialize(&myData);
  std::cout << "Serialized value: " << serialized << std::endl;

  // Désérialisation de l'instance de Data
  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized Data: Name = " << deserialized->name
            << ", Age = " << deserialized->age << std::endl;

  // Vérification que la désérialisation a fonctionné correctement
  if (myData.name == deserialized->name && myData.age == deserialized->age) {
    std::cout
        << "Success: Deserialization correctly restored the original data."
        << std::endl;
  } else {
    std::cout << "Error: Deserialized data does not match the original."
              << std::endl;
  }

  return 0;
}
