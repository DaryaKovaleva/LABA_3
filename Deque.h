#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>
#include "Sequence.h"

template <class T>
class Deque {
private:
    Sequence<T>* data;

public:
    Deque();
    Deque(T* items, int count);
    Deque(const Deque<T>& other);
    ~Deque();

    void PushFront(T item);
    void PushBack(T item);
    T PopFront();
    T PopBack();
    T Front() const;
    T Back() const;
    int GetSize() const;
    bool IsEmpty() const;

    // Дополнительные операции согласно варианту
    void Sort(bool (*compare)(T, T));
    Deque<T>* Concat(Deque<T>* other);
    Deque<T>* GetSubdeque(int startIndex, int endIndex) const;
    bool ContainsSubsequence(Deque<T>* subsequence) const;
    Deque<T>* Merge(Deque<T>* other, bool (*compare)(T, T));

    // Map, Reduce, Where
    template <typename Func>
    Deque<T>* Map(Func func) const;

    template <typename Func>
    T Reduce(Func func, T startValue) const;

    template <typename Predicate>
    Deque<T>* Where(Predicate pred) const;
};

#include "Deque.tpp"

#endif