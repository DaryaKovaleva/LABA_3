#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class ListSequence : public Sequence<T> {
protected:
    LinkedList<T>* items;

public:
    ListSequence(T* items, int count);
    ListSequence();
    ListSequence(const ListSequence<T>& list);
    explicit ListSequence(const LinkedList<T>& list);
    virtual ~ListSequence();

    T GetFirst() const override;
    T GetLast() const override;
    T Get(int index) const override;
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
    int GetLength() const override;

    void Append(const T& item) override;
    void Prepend(const T& item) override;
    void InsertAt(const T& item, int index) override;
    ListSequence<T>* Concat(Sequence<T>* list) override;

    Sequence<T>* Clone() const override;

protected:
    Sequence<T>* CreateEmpty() const override;
};

#include "ListSequence.tpp"
#endif
