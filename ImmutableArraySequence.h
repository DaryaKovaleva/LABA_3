#ifndef IMMUTABLE_ARRAY_SEQUENCE_H
#define IMMUTABLE_ARRAY_SEQUENCE_H

#include "ArraySequence.h"

template <class T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    ImmutableArraySequence(T* items, int count);
    ImmutableArraySequence();
    ImmutableArraySequence(const ImmutableArraySequence<T>& list);
    explicit ImmutableArraySequence(const DynamicArray<T>&  array);

    // Запрещаем изменяющие операции
    void Append(const T& item) override;
    void Prepend(const T& item) override;
    void InsertAt(const T& item, int index) override;

    // === ДОБАВЛЕНО: объявление Clone ===
    Sequence<T>* Clone() const override;

    // Immutable версии операций
    Sequence<T>* AppendImmutable(const T& item) const;
    Sequence<T>* PrependImmutable(const T& item) const;
    Sequence<T>* InsertAtImmutable(const T& item, int index) const;
};

#include "ImmutableArraySequence.tpp"
#endif
