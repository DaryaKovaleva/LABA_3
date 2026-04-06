#ifndef LIST_SEQUENCE_TPP
#define LIST_SEQUENCE_TPP

#include "ListSequence.h"

template <class T>
ListSequence<T>::ListSequence(T* items, int count) {
    this->items = new LinkedList<T>(items, count);
}

template <class T>
ListSequence<T>::ListSequence() {
    this->items = new LinkedList<T>();
}

template <class T>
ListSequence<T>::ListSequence(const ListSequence<T>& list) {
    items = new LinkedList<T>(*(list.items));
}

template <class T>
ListSequence<T>::ListSequence(const LinkedList<T>& list) {
    items = new LinkedList<T>(list);
}

template <class T>
ListSequence<T>::~ListSequence() {
    delete items;
}

template <class T>
T ListSequence<T>::GetFirst() const {
    return items->GetFirst();
}

template <class T>
T ListSequence<T>::GetLast() const {
    return items->GetLast();
}

template <class T>
T ListSequence<T>::Get(int index) const {
    return items->Get(index);
}

template <class T>
ListSequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex) const {
    LinkedList<T>* subList = items->GetSubList(startIndex, endIndex);
    ListSequence<T>* result = new ListSequence<T>(*subList);
    delete subList;
    return result;
}

template <class T>
int ListSequence<T>::GetLength() const {
    return items->GetLength();
}

template <class T>
void ListSequence<T>::Append(T item) {
    items->Append(item);
}

template <class T>
void ListSequence<T>::Prepend(T item) {
    items->Prepend(item);
}

template <class T>
void ListSequence<T>::InsertAt(T item, int index) {
    items->InsertAt(item, index);
}

template <class T>
ListSequence<T>* ListSequence<T>::Concat(Sequence<T>* list) {
    ListSequence<T>* result = new ListSequence<T>(*this);
    
    for (int i = 0; i < list->GetLength(); i++) {
        result->Append(list->Get(i));
    }
    
    return result;
}

template <class T>
Sequence<T>* ListSequence<T>::CreateEmpty() const {
    return new ListSequence<T>();
}

// === ДОБАВЛЕНО: реализация Clone для полиморфного копирования ===
template <class T>
Sequence<T>* ListSequence<T>::Clone() const {
    return new ListSequence<T>(*this);
}

// Явное инстанциирование
template class ListSequence<int>;
template class ListSequence<double>;
template class ListSequence<std::string>;

#endif