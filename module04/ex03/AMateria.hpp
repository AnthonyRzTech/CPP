#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;
class AMateria {
protected:
  std::string type;

public:
  // Constructors
  AMateria(void);
  AMateria(std::string const &type);
  virtual ~AMateria(void);

  // Getters
  std::string const &getType() const;

  // Member Functions
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
