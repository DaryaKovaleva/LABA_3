#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "Sequence.h"

template <class T>
class Stack {
private:
    Sequence<T>* data;

public:
    Stack();
    Stack(T* items, int count);
    Stack(const Stack<T>& other);
    ~Stack();

    void Push(T item);
    T Pop();
    T Peek() const;
    int GetSize() const;
    bool IsEmpty() const;

    // Дополнительные операции согласно варианту (сортировка, map, reduce, where, concat и др.)
    void Sort(bool (*compare)(T, T));
    Stack<T>* Concat(Stack<T>* other);
    Stack<T>* GetSubstack(int startIndex, int endIndex) const;
    bool ContainsSubsequence(Stack<T>* subsequence) const;

    // Map, Reduce, Where
    template <typename Func>
    Stack<T>* Map(Func func) const;

    template <typename Func>
    T Reduce(Func func, T startValue) const;

    template <typename Predicate>
    Stack<T>* Where(Predicate pred) const;
};

#include "Stack.tpp"

#endif