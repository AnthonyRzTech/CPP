#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *storage[4];
  int storageCount;

public:
  // Constructors
  MateriaSource(void);
  MateriaSource(MateriaSource const &src);
  ~MateriaSource(void);

  // Operators
  MateriaSource &operator=(MateriaSource const &src);

  // Member Functions
  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
};

#endif
