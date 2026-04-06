#ifndef DEQUE_TPP
#define DEQUE_TPP

#include "Deque.h"
#include "ListSequence.h"

template <class T>
Deque<T>::Deque() {
    data = new ListSequence<T>();
}

template <class T>
Deque<T>::Deque(T* items, int count) {
    data = new ListSequence<T>(items, count);
}

// === ИСПРАВЛЕНО: конструктор копирования с использованием Clone() ===
template <class T>
Deque<T>::Deque(const Deque<T>& other) {
    if (other.data != nullptr) {
        data = other.data->Clone();
    } else {
        data = nullptr;
    }
}

template <class T>
Deque<T>::~Deque() {
    delete data;
}

template <class T>
void Deque<T>::PushFront(T item) {
    data->Prepend(item);
}

template <class T>
void Deque<T>::PushBack(T item) {
    data->Append(item);
}

template <class T>
T Deque<T>::PopFront() {
    if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    T item = data->GetFirst();
    
    if (data->GetLength() == 1) {
        delete data;
        data = new ListSequence<T>();
    } else {
        Sequence<T>* newData = data->GetSubsequence(1, data->GetLength() - 1);
        delete data;
        data = newData;
    }
    
    return item;
}

template <class T>
T Deque<T>::PopBack() {
    if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    T item = data->GetLast();
    
    if (data->GetLength() == 1) {
        delete data;
        data = new ListSequence<T>();
    } else {
        Sequence<T>* newData = data->GetSubsequence(0, data->GetLength() - 2);
        delete data;
        data = newData;
    }
    
    return item;
}

template <class T>
T Deque<T>::Front() const {
    if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    return data->GetFirst();
}

template <class T>
T Deque<T>::Back() const {
    if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }
    return data->GetLast();
}

template <class T>
int Deque<T>::GetSize() const {
    return data->GetLength();
}

template <class T>
bool Deque<T>::IsEmpty() const {
    return data->GetLength() == 0;
}

template <class T>
void Deque<T>::Sort(bool (*compare)(T, T)) {
    int size = GetSize();
    T* arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = data->Get(i);
    }
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (!compare(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    delete data;
    data = new ListSequence<T>(arr, size);
    delete[] arr;
}

template <class T>
Deque<T>* Deque<T>::Concat(Deque<T>* other) {
    Deque<T>* result = new Deque<T>(*this);
    
    for (int i = 0; i < other->GetSize(); i++) {
        result->PushBack(other->data->Get(i));
    }
    
    return result;
}

template <class T>
Deque<T>* Deque<T>::GetSubdeque(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= GetSize() || startIndex > endIndex) {
        throw std::out_of_range("Invalid indices");
    }
    
    Sequence<T>* subseq = data->GetSubsequence(startIndex, endIndex);
    Deque<T>* result = new Deque<T>();
    delete result->data;
    result->data = subseq;
    
    return result;
}

template <class T>
bool Deque<T>::ContainsSubsequence(Deque<T>* subsequence) const {
    int mainLen = GetSize();
    int subLen = subsequence->GetSize();
    
    if (subLen == 0) return true;
    if (subLen > mainLen) return false;
    
    for (int i = 0; i <= mainLen - subLen; i++) {
        bool found = true;
        for (int j = 0; j < subLen; j++) {
            if (data->Get(i + j) != subsequence->data->Get(j)) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    
    return false;
}

template <class T>
Deque<T>* Deque<T>::Merge(Deque<T>* other, bool (*compare)(T, T)) {
    Deque<T>* result = new Deque<T>();
    int i = 0, j = 0;
    
    while (i < GetSize() && j < other->GetSize()) {
        if (compare(data->Get(i), other->data->Get(j))) {
            result->PushBack(data->Get(i));
            i++;
        } else {
            result->PushBack(other->data->Get(j));
            j++;
        }
    }
    
    while (i < GetSize()) {
        result->PushBack(data->Get(i));
        i++;
    }
    
    while (j < other->GetSize()) {
        result->PushBack(other->data->Get(j));
        j++;
    }
    
    return result;
}

template <class T>
template <typename Func>
Deque<T>* Deque<T>::Map(Func func) const {
    Deque<T>* result = new Deque<T>();
    for (int i = 0; i < GetSize(); i++) {
        result->PushBack(func(data->Get(i)));
    }
    return result;
}

template <class T>
template <typename Func>
T Deque<T>::Reduce(Func func, T startValue) const {
    T result = startValue;
    for (int i = 0; i < GetSize(); i++) {
        result = func(result, data->Get(i));
    }
    return result;
}

template <class T>
template <typename Predicate>
Deque<T>* Deque<T>::Where(Predicate pred) const {
    Deque<T>* result = new Deque<T>();
    for (int i = 0; i < GetSize(); i++) {
        T item = data->Get(i);
        if (pred(item)) {
            result->PushBack(item);
        }
    }
    return result;
}

// Явное инстанциирование
template class Deque<int>;
template class Deque<double>;
template class Deque<std::string>;

#endif