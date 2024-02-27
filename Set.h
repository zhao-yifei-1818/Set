
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
    delete[] items;
    currentSize = other.currentSize;
    capacity = other.capacity;
    items = new T[capacity];
    for (int i = 0; i < currentSize; i++) {
      items[i] = other.items[i];
    }
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

template<typename T>
void Set<T>::add(T item)
{
  if (!contains(item)) {
    if (currentSize == capacity) {
      capacity *= 2;
      T* newItems = new T[capacity];
      for (int i = 0; i < currentSize; i++) {
        newItems[i] = items[i];
      }
      delete[] items;
      items = newItems;
    }
    items[currentSize++] = item;
  }
}

template<typename T>
int Set<T>::getSize() const
{
  return currentSize;
}

template<typename T>
void Set<T>::remove(T item)
{
  for (int i = 0; i < currentSize; i++) {
    if (items[i] == item) {
      items[i] = items[--currentSize];
      return;
    }
  }
}

template<typename T>
void Set<T>::clear()
{
  currentSize = 0;
}

template<typename T>
T Set<T>::removeSmallest()
{
  if (currentSize == 0) {
    throw out_of_range("Set is empty");
  }
  int minIndex = 0;
  for (int i = 1; i < currentSize; i++) {
    if (items[i] < items[minIndex]) {
      minIndex = i;
    }
  }
  T smallest = items[minIndex];
  items[minIndex] = items[--currentSize];
  return smallest;
}

template<typename T>
bool Set<T>::operator==(const Set& other) const
{
  if (currentSize != other.currentSize) {
    return false;
  }
  for (int i = 0; i < currentSize; i++) {
    if (!other.contains(items[i])) {
      return false;
    }
  }
  return true;
}
template<typename T>
string Set<T>::toString() const
{
  string returnstring;
  returnstring = "{";
  for (int i = 0; i < currentSize; i++) {
    returnstring += items[i];
    if (i != currentSize - 1) {
      returnstring += ", ";
    }
  }
  returnstring += "}";
  return returnstring.str();
}

#endif // SET_H
