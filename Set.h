
#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;
template<typename T>
class Set {
private:
  T* items;
  int currentSize;
  int capacity;

public:
  Set();                                  // initial capacity of 8
  Set(const Set& other);                  // copy constructor
  Set<T>& operator=(const Set<T>& other); // assignment operator
  ~Set();                                 // destructor

  bool contains(T item) const;

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
  items = new T[capacity];
} // no arg constructor

template<typename T>
Set<T>::~Set()
{
  delete[] items;
} // Destructor

template<typename T>
Set<T>::Set(const Set<T>& other)
{
  currentSize = other.currentSize;
  capacity = other.capacity;

  items = new T[capacity];
  for (int i = 0; i < capacity; i++)
    items[i] = other.items[i];
} // Copy constructor

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
  if (&other != this) {
    return *this;
  }
  delete[] items;
  currentSize = other.currentSize;
  capacity = other.capacity;
  items = new T[other.capacity];
  for (int i = 0; i < capacity; i++) {
    items[i] = other.items[i];
  }
  return *this;
} // assignment operator

template<typename T>
bool Set<T>::contains(T item) const
{
  for (int i = 0; i < currentSize; i++) {
    if (items[i] == item) {
      return true;
    }
  }
  return false;
}

// template<typename T>
// void add(T item)
// {
//   this.item[currentsize] = item;
// }

#endif // SET_H
