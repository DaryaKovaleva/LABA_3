#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <string>

template <class T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    DynamicArray();
    DynamicArray(T* items, int count);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T>& dynamicArray);
    ~DynamicArray();

    T Get(int index) const;
    int GetSize() const;
    void Set(int index, T value);
    void Resize(int newSize);
    DynamicArray<T> operator=(const DynamicArray<T>&);

};

#include "DynamicArray.tpp"

#endif
