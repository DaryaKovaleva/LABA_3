#ifndef ARRAY_SEQUENCE_TPP
#define ARRAY_SEQUENCE_TPP

#include "ArraySequence.h"

template <class T>
ArraySequence<T>::ArraySequence(T* items, int count) 
    : items(new DynamicArray<T>(items, count)) {}

template <class T>
ArraySequence<T>::ArraySequence() 
    : items(new DynamicArray<T>()) {}

template <class T>
ArraySequence<T>::ArraySequence(const ArraySequence<T>& list) 
    : items(new DynamicArray<T>(*(list.items))) {}

template <class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T>& array) 
    : items(new DynamicArray<T>(array)) {}

template <class T>
ArraySequence<T>::~ArraySequence() {
    delete items;
}

template <class T>
T ArraySequence<T>::GetFirst() const {
    if (GetLength() == 0) {
        throw std::out_of_range("Sequence is empty");
    }
    return items->Get(0);
}

template <class T>
T ArraySequence<T>::GetLast() const {
    if (GetLength() == 0) {
        throw std::out_of_range("Sequence is empty");
    }
    return items->Get(GetLength() - 1);
}

template <class T>
T ArraySequence<T>::Get(int index) const {
    return items->Get(index);
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= GetLength() || startIndex > endIndex) {
        throw std::out_of_range("Invalid indices");
    }

    ArraySequence<T>* result = new ArraySequence<T>();
    for (int i = startIndex; i <= endIndex; i++) {
        result->Append(items->Get(i));
    }
    return result;
}

template <class T>
int ArraySequence<T>::GetLength() const {
    return items->GetSize();
}

template <class T>
void ArraySequence<T>::Append(const T& item) {
    int oldSize = items->GetSize();
    items->Resize(oldSize + 1);
    items->Set(oldSize, item);
}

template <class T>
void ArraySequence<T>::Prepend(const T& item) {
    int oldSize = items->GetSize();
    items->Resize(oldSize + 1);
    
    for (int i = oldSize; i > 0; i--) {
        items->Set(i, items->Get(i - 1));
    }
    items->Set(0, item);
}

template <class T>
void ArraySequence<T>::InsertAt(const T& item, int index) {
    if (index < 0 || index > GetLength()) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == GetLength()) {
        Append(item);
        return;
    }
    
    int oldSize = items->GetSize();
    items->Resize(oldSize + 1);
    
    for (int i = oldSize; i > index; i--) {
        items->Set(i, items->Get(i - 1));
    }
    items->Set(index, item);
}

template <class T>
ArraySequence<T>* ArraySequence<T>::Concat(Sequence<T>* list) {
    ArraySequence<T>* result = new ArraySequence<T>(*this);
    
    for (int i = 0; i < list->GetLength(); i++) {
        result->Append(list->Get(i));
    }
    
    return result;
}

template <class T>
T& ArraySequence<T>::operator[](int index) {
    if (index < 0 || index >= GetLength()) {
        throw std::out_of_range("Index out of range");
    }
    
    static T temp;
    temp = items->Get(index);
    return temp;
}

template <class T>
const T& ArraySequence<T>::operator[](int index) const {
    if (index < 0 || index >= GetLength()) {
        throw std::out_of_range("Index out of range");
    }
    
    static T temp;
    temp = items->Get(index);
    return temp;
}

template <class T>
Sequence<T>* ArraySequence<T>::CreateEmpty() const {
    return new ArraySequence<T>();
}

template <class T>
Sequence<T>* ArraySequence<T>::Clone() const {
    return new ArraySequence<T>(*this);
}

// Явное инстанциирование
template class ArraySequence<int>;
template class ArraySequence<double>;
template class ArraySequence<std::string>;

#endif
