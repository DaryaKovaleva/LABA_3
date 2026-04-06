#include <iostream>
#include <string>
#include "Tests.h"

using namespace std;

// Функция для вывода результата теста
void PrintTestResult(const string& testName, bool passed) {
    cout << (passed ? "[PASS] " : "[FAIL] ") << testName << endl;
}

// ==================== ЗАПУСК ВСЕХ ТЕСТОВ ====================

bool RunAllTests() {
    cout << "\n========== RUNNING TESTS ==========" << endl;
    int passed = 0;
    int total = 0;
    
    // Тесты DynamicArray
    PrintTestResult("DynamicArrayCreation", TestDynamicArrayCreation()); passed += TestDynamicArrayCreation() ? 1 : 0; total++;
    PrintTestResult("DynamicArrayGetSet", TestDynamicArrayGetSet()); passed += TestDynamicArrayGetSet() ? 1 : 0; total++;
    PrintTestResult("DynamicArrayResize", TestDynamicArrayResize()); passed += TestDynamicArrayResize() ? 1 : 0; total++;
    PrintTestResult("DynamicArrayExceptions", TestDynamicArrayExceptions()); passed += TestDynamicArrayExceptions() ? 1 : 0; total++;
    
    // Тесты LinkedList
    PrintTestResult("LinkedListCreation", TestLinkedListCreation()); passed += TestLinkedListCreation() ? 1 : 0; total++;
    PrintTestResult("LinkedListAppendPrepend", TestLinkedListAppendPrepend()); passed += TestLinkedListAppendPrepend() ? 1 : 0; total++;
    PrintTestResult("LinkedListInsertAt", TestLinkedListInsertAt()); passed += TestLinkedListInsertAt() ? 1 : 0; total++;
    PrintTestResult("LinkedListGetSubList", TestLinkedListGetSubList()); passed += TestLinkedListGetSubList() ? 1 : 0; total++;
    PrintTestResult("LinkedListExceptions", TestLinkedListExceptions()); passed += TestLinkedListExceptions() ? 1 : 0; total++;
    
    // Тесты ArraySequence
    PrintTestResult("ArraySequenceCreation", TestArraySequenceCreation()); passed += TestArraySequenceCreation() ? 1 : 0; total++;
    PrintTestResult("ArraySequenceAppendPrepend", TestArraySequenceAppendPrepend()); passed += TestArraySequenceAppendPrepend() ? 1 : 0; total++;
    PrintTestResult("ArraySequenceInsertAt", TestArraySequenceInsertAt()); passed += TestArraySequenceInsertAt() ? 1 : 0; total++;
    PrintTestResult("ArraySequenceGetSubsequence", TestArraySequenceGetSubsequence()); passed += TestArraySequenceGetSubsequence() ? 1 : 0; total++;
    PrintTestResult("ArraySequenceMapReduce", TestArraySequenceMapReduce()); passed += TestArraySequenceMapReduce() ? 1 : 0; total++;
    PrintTestResult("ArraySequenceWhere", TestArraySequenceWhere()); passed += TestArraySequenceWhere() ? 1 : 0; total++;
    
    // Тесты ListSequence
    PrintTestResult("ListSequenceOperations", TestListSequenceOperations()); passed += TestListSequenceOperations() ? 1 : 0; total++;
    PrintTestResult("ListSequenceMapReduce", TestListSequenceMapReduce()); passed += TestListSequenceMapReduce() ? 1 : 0; total++;
    
    // Тесты ImmutableArraySequence
    PrintTestResult("ImmutableArraySequence", TestImmutableArraySequence()); passed += TestImmutableArraySequence() ? 1 : 0; total++;
    PrintTestResult("ImmutableArraySequenceOperations", TestImmutableArraySequenceOperations()); passed += TestImmutableArraySequenceOperations() ? 1 : 0; total++;
    
    // Новые тесты
    PrintTestResult("Queue", TestQueue()); passed += TestQueue() ? 1 : 0; total++;
    PrintTestResult("Stack", TestStack()); passed += TestStack() ? 1 : 0; total++;
    PrintTestResult("Deque", TestDeque()); passed += TestDeque() ? 1 : 0; total++;
    PrintTestResult("Matrix", TestMatrix()); passed += TestMatrix() ? 1 : 0; total++;
    
    cout << "\n========== RESULTS ==========" << endl;
    cout << "Passed: " << passed << "/" << total << endl;
    
    return passed == total;
}