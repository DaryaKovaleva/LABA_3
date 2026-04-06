#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : public Sequence<T> {
protected:
    DynamicArray<T>* items;

public:
    ArraySequence(T* items, int count);
    ArraySequence();
    ArraySequence(const ArraySequence<T>& list);
    explicit ArraySequence(const DynamicArray<T>& array); //зачем нужен?
    virtual ~ArraySequence();

    T GetFirst() const override;
    T GetLast() const override;
    T Get(int index) const override;
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
    int GetLength() const override;

    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    ArraySequence<T>* Concat(Sequence<T>* list) override;

    Sequence<T>* Clone() const override;

    T& operator[](int index);
    const T& operator[](int index) const;

protected:
    Sequence<T>* CreateEmpty() const override;
};

#include "ArraySequence.tpp"
#endif