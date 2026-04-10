#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdexcept>

template <class T>
class Sequence {
public:
    // Виртуальный деструктор
    virtual ~Sequence() {}

    // (интерфейс)
    
    // Декомпозиция
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual int GetLength() const = 0;

    // Операции модификации
    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    // === Метод для полиморфного копирования (КРИТИЧНО ВАЖНО) ===
    virtual Sequence<T>* Clone() const = 0;

    // (реализация внутри класса)
    // Они должны быть внутри класса, чтобы компилятор видел их определение
    
    template <typename Func>
    Sequence<T>* Map(Func func) const {
        Sequence<T>* result = CreateEmpty();
        for (int i = 0; i < GetLength(); i++) {
            result->Append(func(Get(i)));
        }
        return result;
    }

    template <typename Func>
    T Reduce(Func func, T startValue) const {
        T result = startValue;
        for (int i = 0; i < GetLength(); i++) {
            result = func(result, Get(i));
        }
        return result;
    }

    template <typename Predicate>
    Sequence<T>* Where(Predicate pred) const {
        Sequence<T>* result = CreateEmpty();
        for (int i = 0; i < GetLength(); i++) {
            T item = Get(i);
            if (pred(item)) {
                result->Append(item);
            }
        }
        return result;
    }

protected:
    //для создания пустой последовательности того же типа
    virtual Sequence<T>* CreateEmpty() const = 0;
};

#endif
