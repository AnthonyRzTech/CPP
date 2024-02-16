#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>   // for size_t
#include <stdexcept> // for std::exception

template <typename T> class Array {
private:
  T *_elements;
  size_t _size;

public:
  // Default constructor
  Array() : _elements(new T[0]), _size(0) {}

  // Constructor with size
  explicit Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

  // Copy constructor
  Array(const Array &other)
      : _elements(new T[other._size]()), _size(other._size) {
    for (size_t i = 0; i < _size; ++i) {
      _elements[i] = other._elements[i];
    }
  }

  // Destructor
  ~Array() { delete[] _elements; }

  // Assignment operator
  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _elements;
      _size = other._size;
      _elements = new T[_size]();
      for (size_t i = 0; i < _size; ++i) {
        _elements[i] = other._elements[i];
      }
    }
    return *this;
  }

  // Access operator
  T &operator[](size_t index) {
    if (index >= _size)
      throw std::out_of_range("Array index out of bounds");
    return _elements[index];
  }

  // Const access operator for const correctness
  const T &operator[](size_t index) const {
    if (index >= _size)
      throw std::out_of_range("Array index out of bounds");
    return _elements[index];
  }

  // Size accessor
  size_t size() const { return _size; }
};

#endif
