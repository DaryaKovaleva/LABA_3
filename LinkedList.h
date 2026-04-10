#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <string>

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        
        Node(const T& value);
    };

    Node* head;
    Node* tail;
    int length;

    Node* GetNodeAt(int index) const;

public:
    LinkedList(T* items, int count);
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

    T GetFirst() const;
    T GetLast() const;
    T Get(int index) const;
    LinkedList<T>* GetSubList(int startIndex, int endIndex) const;
    int GetLength() const;

    void Append(const T& item);
    void Prepend(const T& item);
    void InsertAt(const T& item, int index);
    LinkedList<T>* Concat(LinkedList<T>* list);
    void Clear();
};

#include "LinkedList.tpp"

#endif
