#include "Brain.hpp"
#include <iostream>
#include <sstream> // Nécessaire pour std::ostringstream

Brain::Brain() {
  for (int i = 0; i < 100; ++i) {
    std::ostringstream convert; // Créer un objet stringstream
    convert << "Idea #" << i;   // Alimenter l'integer dedans
    ideas[i] = convert.str();   // Utiliser la représentation en chaîne
  }
  std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) { *this = other; }

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < 100; ++i) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }
