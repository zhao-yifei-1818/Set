
#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;
template<typename T>
class Set {
private:
  T* item;
  int currentSize;
  int capacity;

public:
  Set();                                          // initial capacity of 8
  Set(const Set& other);                          // copy constructor
  Set<T>& Set<T>::operator=(const Set<T>& other); // assignment operator
  ~Set();
  void add(T item);
  int getSize() const;
  void remove(T item);
  void clear();
  T removeSmallest();
  bool operator==(const Set& other) const;
  string toString() const;
  Set intersectionWith(const Set& other) const;
};

template<typename T>
Set<T>::Set()
{
  currentSize = 0;
  capacity = 8;
  item = new T[capacity];
} // no arg constructor

template<typename T>
Set<T>::~Set()
{
  delete[] item;
} // Destructor

template<typename T>
Set<T>::Set(const Set<T>& other)
{
  currentSize = other.currentSize;
  capacity = other.capacity;

  item = new T[capacity];
  for (int i = 0; i < capacity; i++)
    item[i] = other.item[i];
} // Copy constructor

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
  if (&other != this) {
    return *this;
  }
  currentSize = other.currentSize;
  capacity = other.capacity;
  delete[] item;
  item = new T[other.capacity];
  for (int i = 0; i < capacity; i++) {
    item[i] = other.item[i];
  }
  return *this;
} // assignment operator

#endif // SET_H
