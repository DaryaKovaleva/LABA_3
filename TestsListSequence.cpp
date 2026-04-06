#include <iostream>
#include "Tests.h"

using namespace std;

// Статические утилиты (видны только в этом файле)
static int Square(int x) { return x * x; }
static int Sum(int a, int b) { return a + b; }

template <typename T>
static bool CompareSequences(Sequence<T>* actual, T* expected, int expectedLength) {
    if (actual->GetLength() != expectedLength) return false;
    for (int i = 0; i < expectedLength; i++) {
        if (actual->Get(i) != expected[i]) return false;
    }
    return true;
}

// ==================== ТЕСТЫ LIST SEQUENCE ====================

bool TestListSequenceOperations() {
    int arr[] = {10, 20, 30};
    ListSequence<int> seq(arr, 3);
    
    seq.Prepend(5);
    seq.Append(40);
    seq.InsertAt(25, 2);
    
    if (seq.GetLength() != 6) return false;
    if (seq.Get(0) != 5) return false;
    if (seq.Get(1) != 10) return false;
    if (seq.Get(2) != 25) return false;
    if (seq.Get(3) != 20) return false;
    if (seq.Get(4) != 30) return false;
    if (seq.Get(5) != 40) return false;
    
    return true;
}

bool TestListSequenceMapReduce() {
    int arr[] = {1, 2, 3};
    ListSequence<int> seq(arr, 3);
    
    Sequence<int>* squares = seq.Map(Square);
    int expected[] = {1, 4, 9};
    bool mapPassed = CompareSequences(squares, expected, 3);
    delete squares;
    
    if (!mapPassed) return false;
    
    int sum = seq.Reduce(Sum, 0);
    if (sum != 6) return false;
    
    return true;
}