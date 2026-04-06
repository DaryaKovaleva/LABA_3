#include <iostream>
#include "Tests.h"

using namespace std;

// ==================== ТЕСТЫ LINKED LIST ====================

bool TestLinkedListCreation() {
    int arr[] = {10, 20, 30};
    LinkedList<int> ll(arr, 3);
    
    if (ll.GetLength() != 3) return false;
    if (ll.GetFirst() != 10) return false;
    if (ll.GetLast() != 30) return false;
    
    LinkedList<int> ll2;
    if (ll2.GetLength() != 0) return false;
    
    return true;
}

bool TestLinkedListAppendPrepend() {
    LinkedList<int> ll;
    
    ll.Append(10);
    ll.Append(20);
    ll.Prepend(5);
    
    if (ll.GetLength() != 3) return false;
    if (ll.GetFirst() != 5) return false;
    if (ll.Get(1) != 10) return false;
    if (ll.GetLast() != 20) return false;
    
    return true;
}

bool TestLinkedListInsertAt() {
    int arr[] = {1, 2, 4, 5};
    LinkedList<int> ll(arr, 4);
    
    ll.InsertAt(3, 2);
    
    if (ll.GetLength() != 5) return false;
    if (ll.Get(0) != 1) return false;
    if (ll.Get(1) != 2) return false;
    if (ll.Get(2) != 3) return false;
    if (ll.Get(3) != 4) return false;
    if (ll.Get(4) != 5) return false;
    
    return true;
}

bool TestLinkedListGetSubList() {
    int arr[] = {10, 20, 30, 40, 50};
    LinkedList<int> ll(arr, 5);
    
    LinkedList<int>* sub = ll.GetSubList(1, 3);
    
    if (sub->GetLength() != 3) {
        delete sub;
        return false;
    }
    if (sub->Get(0) != 20 || sub->Get(1) != 30 || sub->Get(2) != 40) {
        delete sub;
        return false;
    }
    
    delete sub;
    return true;
}

bool TestLinkedListExceptions() {
    LinkedList<int> ll;
    
    // Тест выброса исключения при GetFirst на пустом списке
    try {
        ll.GetFirst();
        return false;
    } catch (const out_of_range&) {
        // OK
    }
    
    // Тест выброса исключения при Get с неверным индексом
    try {
        ll.Get(0);
        return false;
    } catch (const out_of_range&) {
        // OK
    }
    
    return true;
}