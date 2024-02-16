#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  srand(static_cast<unsigned int>(time(0)) + rand()); // Seed random generator
  int randNum = rand() % 3;
  switch (randNum) {
  case 0:
    std::cout << "Generated: A" << std::endl;
    return new A();
  case 1:
    std::cout << "Generated: B" << std::endl;
    return new B();
  case 2:
    std::cout << "Generated: C" << std::endl;
    return new C();
  default:
    return NULL; // Should never reach here
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "Identified by pointer: A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "Identified by pointer: B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "Identified by pointer: C" << std::endl;
  else
    std::cout << "unknown" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (const std::exception &e) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (const std::exception &e) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (const std::exception &e) {
    std::cout << "unknown" << std::endl;
  }
}

int main() {
  // Generate and identify 5 random objects
  for (int i = 0; i < 5; ++i) {
    std::cout << "\nTest " << i + 1 << std::endl;
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p; // Clean up
  }
  return 0;
}
