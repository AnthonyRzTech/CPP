#include "Zombie.hpp"
#include <new>

Zombie *zombieHorde(int N, std::string name) {

  void *hordeMemory = operator new[](N * sizeof(Zombie));
  Zombie *horde = static_cast<Zombie *>(hordeMemory);

  for (int i = 0; i < N; ++i) {
    new (&horde[i]) Zombie(name);
  }
  return horde;
}
