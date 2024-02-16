#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
/*
int main()
*/

/*int main() {
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  delete j; // should not create a leak
  delete i;
  return 0;
}
*/
// Test 1: Création et destruction de Dog et Cat
/*
{
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    delete dog;
    delete cat;
}
*/

// Test 2: Vérification des sons des animaux
int main() {
  Animal *animals[2];
  animals[0] = new Dog();
  animals[1] = new Cat();
  for (int i = 0; i < 2; ++i) {
    animals[i]->makeSound();
    delete animals[i];
  }
}

// Test 3: Test de la copie profonde pour Dog
/*
{
    Dog originalDog;
    Dog copyDog = originalDog;
    // Modifier une idée de copyDog pour s'assurer que originalDog reste
inchangé copyDog.setIdea(0, "Nouvelle idée"); originalDog.displayIdeas();
    copyDog.displayIdeas();
}
*/

// Test 4: Test de la copie profonde pour Cat
/*
{
    Cat originalCat;
    Cat copyCat = originalCat;
    // Modifier une idée de copyCat pour s'assurer que originalCat reste
inchangé copyCat.setIdea(0, "Nouvelle idée"); originalCat.displayIdeas();
    copyCat.displayIdeas();
}
*/

// Test 5: Vérification de la gestion de la mémoire
/*
{
    Animal* animals[4];
    for (int i = 0; i < 2; ++i) animals[i] = new Dog();
    for (int i = 2; i < 4; ++i) animals[i] = new Cat();
    for (int i = 0; i < 4; ++i) delete animals[i];
}
*/
// return 0;
// }
