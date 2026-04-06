#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "Queue.h"
#include "ArraySequence.h"

template <class T>
Queue<T>::Queue() {
    data = new ArraySequence<T>();
}

template <class T>
Queue<T>::Queue(T* items, int count) {
    data = new ArraySequence<T>(items, count);
}

// === ИСПРАВЛЕНО: конструктор копирования с использованием Clone() ===
template <class T>
Queue<T>::Queue(const Queue<T>& other) {
    if (other.data != nullptr) {
        data = other.data->Clone();
    } else {
        data = nullptr;
    }
}

template <class T>
Queue<T>::~Queue() {
    delete data;
}

template <class T>
void Queue<T>::Enqueue(T item) {
    data->Append(item);
}

template <class T>
T Queue<T>::Dequeue() {
    if (IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T item = data->GetFirst();
    
    if (data->GetLength() == 1) {
        delete data;
        data = new ArraySequence<T>();
    } else {
        Sequence<T>* newData = data->GetSubsequence(1, data->GetLength() - 1);
        delete data;
        data = newData;
    }
    
    return item;
}

template <class T>
T Queue<T>::Peek() const {
    if (IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data->GetFirst();
}

template <class T>
int Queue<T>::GetSize() const {
    return data->GetLength();
}

template <class T>
bool Queue<T>::IsEmpty() const {
    return data->GetLength() == 0;
}

template <class T>
Queue<T>* Queue<T>::Concat(Queue<T>* other) {
    Queue<T>* result = new Queue<T>(*this);
    
    for (int i = 0; i < other->GetSize(); i++) {
        result->Enqueue(other->data->Get(i));
    }
    
    return result;
}

template <class T>
Queue<T>* Queue<T>::GetSubqueue(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= GetSize() || startIndex > endIndex) {
        throw std::out_of_range("Invalid indices");
    }
    
    Sequence<T>* subseq = data->GetSubsequence(startIndex, endIndex);
    Queue<T>* result = new Queue<T>();
    delete result->data;
    result->data = subseq;
    
    return result;
}

template <class T>
bool Queue<T>::ContainsSubsequence(Queue<T>* subsequence) const {
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
void Queue<T>::Split(bool (*predicate)(T), Queue<T>*& first, Queue<T>*& second) {
    first = new Queue<T>();
    second = new Queue<T>();
    
    for (int i = 0; i < GetSize(); i++) {
        T item = data->Get(i);
        if (predicate(item)) {
            first->Enqueue(item);
        } else {
            second->Enqueue(item);
        }
    }
}

template <class T>
template <typename Func>
Queue<T>* Queue<T>::Map(Func func) const {
    Queue<T>* result = new Queue<T>();
    for (int i = 0; i < GetSize(); i++) {
        result->Enqueue(func(data->Get(i)));
    }
    return result;
}

template <class T>
template <typename Func>
T Queue<T>::Reduce(Func func, T startValue) const {
    T result = startValue;
    for (int i = 0; i < GetSize(); i++) {
        result = func(result, data->Get(i));
    }
    return result;
}

template <class T>
template <typename Predicate>
Queue<T>* Queue<T>::Where(Predicate pred) const {
    Queue<T>* result = new Queue<T>();
    for (int i = 0; i < GetSize(); i++) {
        T item = data->Get(i);
        if (pred(item)) {
            result->Enqueue(item);
        }
    }
    return result;
}

// Явное инстанциирование
template class Queue<int>;
template class Queue<double>;
template class Queue<std::string>;

#endif