#ifndef TESTSLIB_H
#define TESTSLIB_H

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
