#include "Zombie.hpp"

int main() {
  Zombie *heapZombie = new Zombie("HeapZombie");
  heapZombie->announce();

  randomChump("StackZombie");

  delete heapZombie;
  return 0;
}
