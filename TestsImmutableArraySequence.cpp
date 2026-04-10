#include <iostream>
#include "Tests.h"
#include "ImmutableArraySequence.h"

using namespace std;

// ==================== ТЕСТЫ IMMUTABLE ARRAY SEQUENCE ====================

bool TestImmutableArraySequence() {
    int arr[] = {1, 2, 3};
    ImmutableArraySequence<int> seq(arr, 3);
    
    // Проверка, что исходная последовательность не изменилась
    Sequence<int>* newSeq = seq.AppendImmutable(4);
    
    if (seq.GetLength() != 3) {
        delete newSeq;
        return false;
    }
    if (newSeq->GetLength() != 4) {
        delete newSeq;
        return false;
    }
    if (newSeq->Get(3) != 4) {
        delete newSeq;
        return false;
    }
    
    delete newSeq;
    return true;
}

bool TestImmutableArraySequenceOperations() {
    int arr[] = {10, 20, 30};
    ImmutableArraySequence<int> seq(arr, 3);
    
    // Тест PrependImmutable
    Sequence<int>* prepended = seq.PrependImmutable(5);
    if (prepended->GetLength() != 4) {
        delete prepended;
        return false;
    }
    if (prepended->Get(0) != 5) {
        delete prepended;
        return false;
    }
    delete prepended;
    
    // Тест InsertAtImmutable
    Sequence<int>* inserted = seq.InsertAtImmutable(25, 2);
    if (inserted->GetLength() != 4) {
        delete inserted;
        return false;
    }
    if (inserted->Get(2) != 25) {
        delete inserted;
        return false;
    }
    delete inserted;
    
    // Проверка, что изменяющие методы выбрасывают исключения
    try {
        ImmutableArraySequence<int> seq2(arr, 3);
        seq2.Append(100);
        return false;
    } catch (const runtime_error&) {
        // OK
    }
    
    return true;
}
