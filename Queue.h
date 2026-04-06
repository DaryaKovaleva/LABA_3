#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include "Sequence.h"

template <class T>
class Queue {
private:
    Sequence<T>* data;

public:
    Queue();
    Queue(T* items, int count);
    Queue(const Queue<T>& other);
    ~Queue();

    void Enqueue(T item);
    T Dequeue();
    T Peek() const;
    int GetSize() const;
    bool IsEmpty() const;

    // Дополнительные операции согласно варианту
    Queue<T>* Concat(Queue<T>* other);
    Queue<T>* GetSubqueue(int startIndex, int endIndex) const;
    bool ContainsSubsequence(Queue<T>* subsequence) const;
    void Split(bool (*predicate)(T), Queue<T>*& first, Queue<T>*& second);

    // Map, Reduce, Where (монадные операции)
    template <typename Func>
    Queue<T>* Map(Func func) const;

    template <typename Func>
    T Reduce(Func func, T startValue) const;

    template <typename Predicate>
    Queue<T>* Where(Predicate pred) const;
};

#include "Queue.tpp"

#endif