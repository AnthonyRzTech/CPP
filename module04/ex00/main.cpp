#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

/*int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  return 0;
}
*/

// Test 1: Testing polymorphic behavior with Animal pointers
int main() {
  Animal *animals[4];

  for (int i = 0; i < 2; ++i) {
    animals[i] = new Dog();
  }
  for (int i = 2; i < 4; ++i) {
    animals[i] = new Cat();
  }

  for (int i = 0; i < 4; ++i) {
    animals[i]->makeSound();
  }

  for (int i = 0; i < 4; ++i) {
    delete animals[i];
  }

  return 0;
}

/*
// Test 2: Direct instantiation and method calls
int main() {
    Cat cat;
    Dog dog;
    WrongCat wrongCat;
    WrongAnimal wrongAnimal;

    cat.makeSound();
    dog.makeSound();
    wrongCat.makeSound();
    wrongAnimal.makeSound();

    return 0;
}
*/

/*
// Test 3: Testing the slicing problem with WrongAnimal and WrongCat
int main() {
    WrongAnimal wrongAnimalBase;
    WrongCat wrongCatDerived;

    WrongAnimal sliced = wrongCatDerived; // Object slicing, wrongCatDerived is
sliced to WrongAnimal sliced.makeSound();

    return 0;
}
*/

/*
// Test 4: Using references to access overridden methods
int main() {
    WrongAnimal wrongAnimal;
    WrongCat wrongCat;

    WrongAnimal& refWrongAnimal = wrongCat; // Reference to WrongCat as
WrongAnimal refWrongAnimal.makeSound(); // Should still call WrongAnimal's
makeSound due to non-virtual function

    return 0;
}
*/

/*
// Test 5: Dynamic allocation and polymorphism with WrongAnimal hierarchy
int main() {
    WrongAnimal* ptrWrongAnimal = new WrongCat(); // Pointer of type WrongAnimal
pointing to WrongCat ptrWrongAnimal->makeSound(); // Due to non-virtual
makeSound, WrongAnimal's sound is produced

    delete ptrWrongAnimal;

    return 0;
}
*/
