#ifndef TESTS_H
#define TESTS_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "ImmutableArraySequence.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "Matrix.h"

// Функция для вывода результата теста
void PrintTestResult(const std::string& testName, bool passed);

// Запуск всех тестов
bool RunAllTests();

// Тесты DynamicArray
bool TestDynamicArrayCreation();
bool TestDynamicArrayGetSet();
bool TestDynamicArrayResize();
bool TestDynamicArrayExceptions();

// Тесты LinkedList
bool TestLinkedListCreation();
bool TestLinkedListAppendPrepend();
bool TestLinkedListInsertAt();
bool TestLinkedListGetSubList();
bool TestLinkedListExceptions();

// Тесты ArraySequence
bool TestArraySequenceCreation();
bool TestArraySequenceAppendPrepend();
bool TestArraySequenceInsertAt();
bool TestArraySequenceGetSubsequence();
bool TestArraySequenceMapReduce();
bool TestArraySequenceWhere();

// Тесты ListSequence
bool TestListSequenceOperations();
bool TestListSequenceMapReduce();

// Тесты ImmutableArraySequence
bool TestImmutableArraySequence();
bool TestImmutableArraySequenceOperations();

// Новые тесты
bool TestQueue();
bool TestStack();
bool TestDeque();
bool TestMatrix();

#endif
