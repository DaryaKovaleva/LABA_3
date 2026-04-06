#ifndef STACK_TPP
#define STACK_TPP

#include <algorithm>
#include "Stack.h"
#include "ArraySequence.h"

template <class T>
Stack<T>::Stack() {
    data = new ArraySequence<T>();
}

template <class T>
Stack<T>::Stack(T* items, int count) {
    data = new ArraySequence<T>(items, count);
}

// === ИСПРАВЛЕНО: конструктор копирования с использованием Clone() ===
template <class T>
Stack<T>::Stack(const Stack<T>& other) {
    if (other.data != nullptr) {
        data = other.data->Clone();
    } else {
        data = nullptr;
    }
}

template <class T>
Stack<T>::~Stack() {
    delete data;
}

template <class T>
void Stack<T>::Push(T item) {
    data->Append(item);
}

template <class T>
T Stack<T>::Pop() {
    if (IsEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    T item = data->GetLast();
    
    if (data->GetLength() == 1) {
        delete data;
        data = new ArraySequence<T>();
    } else {
        Sequence<T>* newData = data->GetSubsequence(0, data->GetLength() - 2);
        delete data;
        data = newData;
    }
    
    return item;
}

template <class T>
T Stack<T>::Peek() const {
    if (IsEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data->GetLast();
}

template <class T>
int Stack<T>::GetSize() const {
    return data->GetLength();
}

template <class T>
bool Stack<T>::IsEmpty() const {
    return data->GetLength() == 0;
}

template <class T>
void Stack<T>::Sort(bool (*compare)(T, T)) {
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
    data = new ArraySequence<T>(arr, size);
    delete[] arr;
}

template <class T>
Stack<T>* Stack<T>::Concat(Stack<T>* other) {
    Stack<T>* result = new Stack<T>(*this);
    
    for (int i = 0; i < other->GetSize(); i++) {
        result->Push(other->data->Get(i));
    }
    
    return result;
}

template <class T>
Stack<T>* Stack<T>::GetSubstack(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= GetSize() || startIndex > endIndex) {
        throw std::out_of_range("Invalid indices");
    }
    
    Sequence<T>* subseq = data->GetSubsequence(startIndex, endIndex);
    Stack<T>* result = new Stack<T>();
    delete result->data;
    result->data = subseq;
    
    return result;
}

template <class T>
bool Stack<T>::ContainsSubsequence(Stack<T>* subsequence) const {
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
template <typename Func>
Stack<T>* Stack<T>::Map(Func func) const {
    Stack<T>* result = new Stack<T>();
    for (int i = 0; i < GetSize(); i++) {
        result->Push(func(data->Get(i)));
    }
    return result;
}

template <class T>
template <typename Func>
T Stack<T>::Reduce(Func func, T startValue) const {
    T result = startValue;
    for (int i = 0; i < GetSize(); i++) {
        result = func(result, data->Get(i));
    }
    return result;
}

template <class T>
template <typename Predicate>
Stack<T>* Stack<T>::Where(Predicate pred) const {
    Stack<T>* result = new Stack<T>();
    for (int i = 0; i < GetSize(); i++) {
        T item = data->Get(i);
        if (pred(item)) {
            result->Push(item);
        }
    }
    return result;
}

// Явное инстанциирование
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;

#endif