#ifndef IMMUTABLE_ARRAY_SEQUENCE_TPP
#define IMMUTABLE_ARRAY_SEQUENCE_TPP

#include "ImmutableArraySequence.h"

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(T* items, int count) 
    : ArraySequence<T>(items, count) {}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence() 
    : ArraySequence<T>() {}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(const ImmutableArraySequence<T>& list) 
    : ArraySequence<T>(list) {}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(const DynamicArray<T>& array) 
    : ArraySequence<T>(array) {}

template <class T>
void ImmutableArraySequence<T>::Append([[maybe_unused]]const T& item) {
    throw std::runtime_error("Cannot modify immutable sequence");
}

template <class T>
void ImmutableArraySequence<T>::Prepend([[maybe_unused]]const T& item) {
    throw std::runtime_error("Cannot modify immutable sequence");
}

template <class T>
void ImmutableArraySequence<T>::InsertAt([[maybe_unused]]const T& item, [[maybe_unused]]int index) {
    throw std::runtime_error("Cannot modify immutable sequence");
}

template <class T>
Sequence<T>* ImmutableArraySequence<T>::AppendImmutable(const T& item) const {
    DynamicArray<T>* newArray = new DynamicArray<T>(*(this->items));
    int oldSize = newArray->GetSize();
    newArray->Resize(oldSize + 1);
    newArray->Set(oldSize, item);
    return new ImmutableArraySequence<T>(*newArray);
}

template <class T>
Sequence<T>* ImmutableArraySequence<T>::PrependImmutable(const T& item) const {
    DynamicArray<T>* newArray = new DynamicArray<T>(this->items->GetSize() + 1);
    newArray->Set(0, item);
    for (int i = 0; i < this->items->GetSize(); i++) {
        newArray->Set(i + 1, this->items->Get(i));
    }
    return new ImmutableArraySequence<T>(*newArray);
}

template <class T>
Sequence<T>* ImmutableArraySequence<T>::InsertAtImmutable(const T& item, int index) const {
    if (index < 0 || index > this->GetLength()) {
        throw std::out_of_range("Index out of range");
    }
    
    DynamicArray<T>* newArray = new DynamicArray<T>(this->items->GetSize() + 1);
    
    for (int i = 0; i < index; i++) {
        newArray->Set(i, this->items->Get(i));
    }
    
    newArray->Set(index, item);
    
    for (int i = index; i < this->items->GetSize(); i++) {
        newArray->Set(i + 1, this->items->Get(i));
    }
    
    return new ImmutableArraySequence<T>(*newArray);
}

// === ДОБАВЛЕНО: реализация Clone для полиморфного копирования ===
template <class T>
Sequence<T>* ImmutableArraySequence<T>::Clone() const {
    return new ImmutableArraySequence<T>(*this);
}

// Явное инстанциирование
template class ImmutableArraySequence<int>;
template class ImmutableArraySequence<double>;
template class ImmutableArraySequence<std::string>;

#endif
