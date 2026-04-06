#include <iostream>
#include "Tests.h"

using namespace std;

// Статические утилиты (видны только в этом файле)
static int Square(int x) { return x * x; }
static int Sum(int a, int b) { return a + b; }
static bool IsEven(int x) { return x % 2 == 0; }

template <typename T>
static bool CompareSequences(Sequence<T>* actual, T* expected, int expectedLength) {
    if (actual->GetLength() != expectedLength) return false;
    for (int i = 0; i < expectedLength; i++) {
        if (actual->Get(i) != expected[i]) return false;
    }
    return true;
}

// ==================== ТЕСТЫ ARRAY SEQUENCE ====================

bool TestArraySequenceCreation() {
    int arr[] = {1, 2, 3};
    ArraySequence<int> seq(arr, 3);
    
    if (seq.GetLength() != 3) return false;
    if (seq.GetFirst() != 1) return false;
    if (seq.GetLast() != 3) return false;
    
    ArraySequence<int> seq2;
    if (seq2.GetLength() != 0) return false;
    
    return true;
}

bool TestArraySequenceAppendPrepend() {
    int arr[] = {2, 3, 4};
    ArraySequence<int> seq(arr, 3);
    
    seq.Prepend(1);
    seq.Append(5);
    
    if (seq.GetLength() != 5) return false;
    if (seq.Get(0) != 1) return false;
    if (seq.Get(1) != 2) return false;
    if (seq.Get(2) != 3) return false;
    if (seq.Get(3) != 4) return false;
    if (seq.Get(4) != 5) return false;
    
    return true;
}

bool TestArraySequenceInsertAt() {
    int arr[] = {1, 2, 4, 5};
    ArraySequence<int> seq(arr, 4);
    
    seq.InsertAt(3, 2);
    
    if (seq.GetLength() != 5) return false;
    if (seq.Get(2) != 3) return false;
    
    return true;
}

bool TestArraySequenceGetSubsequence() {
    int arr[] = {10, 20, 30, 40, 50};
    ArraySequence<int> seq(arr, 5);
    
    Sequence<int>* sub = seq.GetSubsequence(1, 3);
    
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

bool TestArraySequenceMapReduce() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> seq(arr, 5);
    
    // Тест Map
    Sequence<int>* squares = seq.Map(Square);
    int expected[] = {1, 4, 9, 16, 25};
    bool mapPassed = CompareSequences(squares, expected, 5);
    delete squares;
    
    if (!mapPassed) return false;
    
    // Тест Reduce
    int sum = seq.Reduce(Sum, 0);
    if (sum != 15) return false;
    
    return true;
}

bool TestArraySequenceWhere() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    ArraySequence<int> seq(arr, 6);
    
    Sequence<int>* evens = seq.Where(IsEven);
    int expected[] = {2, 4, 6};
    bool result = CompareSequences(evens, expected, 3);
    delete evens;
    
    return result;
}