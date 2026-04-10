#ifndef DYNAMIC_ARRAY_TPP
#define DYNAMIC_ARRAY_TPP

#include "DynamicArray.h"

template <class T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0) {} 

template <class T>
DynamicArray<T>::DynamicArray(T* items, int count) {
    if (count < 0) throw std::invalid_argument("Count cannot be negative");
    if (count > 0 && items == nullptr) throw std::invalid_argument("Items array is null");
    
    size = count;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = items[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int size) {
    if (size < 0) throw std::invalid_argument("Size cannot be negative");
    
    this->size = size;
    data = new T[size]();
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& dynamicArray) {
    size = dynamicArray.size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = dynamicArray.data[i];
    }
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <class T>
T DynamicArray<T>::Get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <class T>
int DynamicArray<T>::GetSize() const {
    return size;
}

template <class T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

template <class T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize < 0) throw std::invalid_argument("New size cannot be negative");
    if (newSize == size) return;

    T* newData = new T[newSize]();
    int copySize = (newSize < size) ? newSize : size;
    
    for (int i = 0; i < copySize; i++) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    size = newSize;
}

template <class T>
DynamicArray<T> DynamicArray<T>::operator=(const DynamicArray<T>& rv) {
    delete[] data;
    size = rv.size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rv.data[i];
    }
    return *this;
};

// Явное инстанциирование для часто используемых типов
template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<std::string>;

#endif
