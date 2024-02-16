#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  std::string name;
  int inventoryCount;
  AMateria *inventory[4];
  AMateria *unequiped[4];

public:
  // Constructors
  Character(void);
  Character(std::string const &name);
  Character(Character const &src);
  virtual ~Character(void);

  // Operators
  Character &operator=(Character const &src);

  // Getters
  std::string const &getName() const;

  // Member Functions
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
