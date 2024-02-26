
#ifndef SET_H
#define SET_H

class Set {
private:
  T* item;

public:
  Set();
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

#endif // SET_H
