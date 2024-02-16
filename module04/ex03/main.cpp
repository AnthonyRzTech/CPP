#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  return 0;
}

// int main() {
//  Test 1: Basic functionality of Ice and Cure Materias
/*
{
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    ICharacter* bob = new Character("Bob");
    ice->use(*bob);
    cure->use(*bob);
    delete bob;
    delete ice;
    delete cure;
}
*/

// Test 2: Testing Materia cloning
/*
{
    AMateria* ice = new Ice();
    AMateria* clone = ice->clone();
    ICharacter* bob = new Character("Bob");
    clone->use(*bob);
    delete bob;
    delete ice;
    delete clone;
}
*/

// Test 3: Character equip and use functionality
/*
{
    ICharacter* me = new Character("Me");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    me->equip(ice);
    me->equip(cure);
    ICharacter* bob = new Character("Bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    // Note: Ice and Cure are not deleted to simulate unequip scenario
}
*/

// Test 4: Testing MateriaSource learning and creating Materia
/*
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    ICharacter* bob = new Character("Bob");
    ice->use(*bob);
    cure->use(*bob);
    delete bob;
    delete ice;
    delete cure;
    delete src;
}
*/

// Test 5: Deep copy of Character
/*
{
    Character* original = new Character("Original");
    AMateria* ice = new Ice();
    original->equip(ice);
    Character* copy = new Character(*original);
    ICharacter* bob = new Character("Bob");
    copy->use(0, *bob); // Should work just like the original
    delete bob;
    delete original;
    delete copy;
    // Note: The ice materia is deleted with the original character
}
*/
// return 0;
// }
