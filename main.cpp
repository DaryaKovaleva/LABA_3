#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "ImmutableArraySequence.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "Matrix.h"
#include "Tests.h"

using namespace std;

// Простые функции для тестирования map/reduce
int square(int x) { return x * x; }
int sum(int a, int b) { return a + b; }
bool isEven(int x) { return x % 2 == 0; }
bool greaterInt(int a, int b) { return a < b; }

// Функция для вывода последовательности
template <typename T>
void PrintSequence(Sequence<T>* seq, const string& name) {
    cout << name << ": [";
    for (int i = 0; i < seq->GetLength(); i++) {
        cout << seq->Get(i);
        if (i < seq->GetLength() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Тестирование DynamicArray
void DemoDynamicArray() {
    cout << "\n=== TESTING DYNAMIC ARRAY ===" << endl;
    
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> da(arr, 5);
    
    cout << "Size: " << da.GetSize() << endl;
    cout << "Element at index 2: " << da.Get(2) << endl;
    
    da.Set(2, 10);
    cout << "After Set(2, 10): " << da.Get(2) << endl;
    
    da.Resize(7);
    cout << "After Resize(7), size: " << da.GetSize() << endl;
    da.Set(6, 99);
    cout << "New element at index 6: " << da.Get(6) << endl;
    
    try {
        da.Get(10);
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}

// Тестирование LinkedList
void DemoLinkedList() {
    cout << "\n=== TESTING LINKED LIST ===" << endl;
    
    int arr[] = {10, 20, 30, 40};
    LinkedList<int> ll(arr, 4);
    
    cout << "Length: " << ll.GetLength() << endl;
    cout << "First: " << ll.GetFirst() << ", Last: " << ll.GetLast() << endl;
    cout << "Element at index 2: " << ll.Get(2) << endl;
    
    ll.Append(50);
    ll.Prepend(5);
    cout << "After Append(50) and Prepend(5), first: " << ll.GetFirst() 
         << ", last: " << ll.GetLast() << endl;
    
    ll.InsertAt(25, 3);
    cout << "After InsertAt(25, 3): ";
    for (int i = 0; i < ll.GetLength(); i++) {
        cout << ll.Get(i) << " ";
    }
    cout << endl;
    
    LinkedList<int>* subList = ll.GetSubList(2, 5);
    cout << "SubList(2,5): ";
    for (int i = 0; i < subList->GetLength(); i++) {
        cout << subList->Get(i) << " ";
    }
    cout << endl;
    delete subList;
}

// Тестирование ArraySequence
void DemoArraySequence() {
    cout << "\n=== TESTING ARRAY SEQUENCE (MUTABLE) ===" << endl;
    
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> seq(arr, 5);
    
    PrintSequence(&seq, "Initial sequence");
    cout << "First: " << seq.GetFirst() << ", Last: " << seq.GetLast() << endl;
    
    seq.Append(6);
    seq.Prepend(0);
    cout << "After Append(6) and Prepend(0): ";
    PrintSequence(&seq, "Sequence");
    
    seq.InsertAt(99, 3);
    cout << "After InsertAt(99, 3): ";
    PrintSequence(&seq, "Sequence");
    
    // Тестирование map/reduce
    Sequence<int>* squared = seq.Map(square);
    PrintSequence(squared, "Map(square)");
    
    int total = seq.Reduce(sum, 0);
    cout << "Reduce(sum, 0): " << total << endl;
    
    Sequence<int>* evens = seq.Where(isEven);
    PrintSequence(evens, "Where(isEven)");
    
    delete squared;
    delete evens;
}

// Тестирование ListSequence
void DemoListSequence() {
    cout << "\n=== TESTING LIST SEQUENCE (MUTABLE) ===" << endl;
    
    int arr[] = {100, 200, 300};
    ListSequence<int> seq(arr, 3);
    
    PrintSequence(&seq, "Initial sequence");
    
    seq.Append(400);
    seq.Prepend(50);
    cout << "After Append(400) and Prepend(50): ";
    PrintSequence(&seq, "Sequence");
    
    seq.InsertAt(250, 2);
    cout << "After InsertAt(250, 2): ";
    PrintSequence(&seq, "Sequence");
    
    Sequence<int>* sub = seq.GetSubsequence(1, 4);
    PrintSequence(sub, "Subsequence(1,4)");
    delete sub;
}

// Тестирование ImmutableArraySequence
void DemoImmutableArraySequencefast() {
    cout << "\n=== TESTING IMMUTABLE ARRAY SEQUENCE ===" << endl;
    
    int arr[] = {1, 2, 3};
    ImmutableArraySequence<int> seq(arr, 3);
    
    PrintSequence(&seq, "Original immutable sequence");
    
    // Используем immutable операции
    Sequence<int>* newSeq1 = seq.AppendImmutable(4);
    cout << "After AppendImmutable(4): ";
    PrintSequence(newSeq1, "New sequence");
    cout << "Original still: ";
    PrintSequence(&seq, "Original");
    
    Sequence<int>* newSeq2 = seq.PrependImmutable(0);
    cout << "After PrependImmutable(0): ";
    PrintSequence(newSeq2, "New sequence");
    
    Sequence<int>* newSeq3 = seq.InsertAtImmutable(99, 2);
    cout << "After InsertAtImmutable(99, 2): ";
    PrintSequence(newSeq3, "New sequence");
    
    delete newSeq1;
    delete newSeq2;
    delete newSeq3;
    
    // Проверка, что mutable операции запрещены
    try {
        ImmutableArraySequence<int> seq2(arr, 3);
        seq2.Append(5);
        cout << "This line should not execute" << endl;
    } catch (const exception& e) {
        cout << "Exception caught when trying to modify immutable: " << e.what() << endl;
    }
}

// НОВЫЕ ТЕСТЫ

// Тестирование Queue
void DemoQueue() {
    cout << "\n=== TESTING QUEUE ===" << endl;
    
    int arr[] = {10, 20, 30};
    Queue<int> q(arr, 3);
    
    cout << "Queue size: " << q.GetSize() << endl;
    cout << "Front: " << q.Peek() << endl;
    
    q.Enqueue(40);
    q.Enqueue(50);
    cout << "After Enqueue(40, 50), size: " << q.GetSize() << endl;
    
    cout << "Dequeue: " << q.Dequeue() << endl;
    cout << "Dequeue: " << q.Dequeue() << endl;
    cout << "After dequeue, front: " << q.Peek() << endl;
    
    // Тест Map
    int arr2[] = {1, 2, 3};
    Queue<int> q2(arr2, 3);
    Queue<int>* squared = q2.Map(square);
    cout << "Map(square): ";
    while (!squared->IsEmpty()) {
        cout << squared->Dequeue() << " ";
    }
    cout << endl;
    delete squared;
    
    // Тест Where
    int arr3[] = {1, 2, 3, 4, 5, 6};
    Queue<int> q3(arr3, 6);
    Queue<int>* evens = q3.Where(isEven);
    cout << "Where(isEven): ";
    while (!evens->IsEmpty()) {
        cout << evens->Dequeue() << " ";
    }
    cout << endl;
    delete evens;
}

// Тестирование Stack
void DemoStack() {
    cout << "\n=== TESTING STACK ===" << endl;
    
    int arr[] = {10, 20, 30};
    Stack<int> s(arr, 3);
    
    cout << "Stack size: " << s.GetSize() << endl;
    cout << "Top: " << s.Peek() << endl;
    
    s.Push(40);
    s.Push(50);
    cout << "After Push(40, 50), size: " << s.GetSize() << endl;
    
    cout << "Pop: " << s.Pop() << endl;
    cout << "Pop: " << s.Pop() << endl;
    cout << "After pop, top: " << s.Peek() << endl;
    
    // Тест Sort
    int arr2[] = {5, 2, 8, 1, 9, 3};
    Stack<int> s2(arr2, 6);
    s2.Sort(greaterInt);
    cout << "After sort: ";
    while (!s2.IsEmpty()) {
        cout << s2.Pop() << " ";
    }
    cout << endl;
    
    // Тест Map
    int arr3[] = {1, 2, 3};
    Stack<int> s3(arr3, 3);
    Stack<int>* squared = s3.Map(square);
    cout << "Map(square): ";
    while (!squared->IsEmpty()) {
        cout << squared->Pop() << " ";
    }
    cout << endl;
    delete squared;
}

// Тестирование Deque
void DemoDeque() {
    cout << "\n=== TESTING DEQUE ===" << endl;
    
    Deque<int> d;
    
    d.PushBack(10);
    d.PushBack(20);
    d.PushFront(5);
    d.PushFront(1);
    
    cout << "Front: " << d.Front() << ", Back: " << d.Back() << endl;
    cout << "Size: " << d.GetSize() << endl;
    
    cout << "PopFront: " << d.PopFront() << endl;
    cout << "PopBack: " << d.PopBack() << endl;
    cout << "After pops, front: " << d.Front() << ", back: " << d.Back() << endl;
    
    // Тест Sort
    int arr[] = {5, 2, 8, 1, 9, 3};
    Deque<int> d2(arr, 6);
    d2.Sort(greaterInt);
    cout << "After sort: ";
    while (!d2.IsEmpty()) {
        cout << d2.PopFront() << " ";
    }
    cout << endl;
    
    // Тест Map
    int arr2[] = {1, 2, 3, 4};
    Deque<int> d3(arr2, 4);
    Deque<int>* squared = d3.Map(square);
    cout << "Map(square): ";
    while (!squared->IsEmpty()) {
        cout << squared->PopFront() << " ";
    }
    cout << endl;
    delete squared;
}

// Тестирование Matrix
void DemoMatrix() {
    cout << "\n=== TESTING MATRIX ===" << endl;
    
    // Создание матрицы 2x3
    int items[] = {1, 2, 3, 4, 5, 6};
    Matrix<int> m1(2, 3, items);
    
    cout << "Matrix 2x3:" << endl;
    m1.Print();
    
    cout << "Element at (0,1): " << m1.Get(0, 1) << endl;
    
    m1.Set(1, 2, 99);
    cout << "After Set(1,2,99):" << endl;
    m1.Print();
    
    // Сложение матриц
    int items2[] = {1, 1, 1, 1, 1, 1};
    Matrix<int> m2(2, 3, items2);
    Matrix<int> m3 = m1.Add(m2);
    cout << "Sum of matrices:" << endl;
    m3.Print();
    
    // Умножение на скаляр
    Matrix<int> m4 = m1.MultiplyByScalar(2);
    cout << "Multiply by scalar 2:" << endl;
    m4.Print();
    
    // Норма
    double norm = m1.Norm();
    cout << "Norm: " << norm << endl;
    
    // Элементарные преобразования строк
    m1.SwapRows(0, 1);
    cout << "After swapping rows 0 and 1:" << endl;
    m1.Print();
    
    m1.MultiplyRow(0, 2);
    cout << "After multiplying row 0 by 2:" << endl;
    m1.Print();
    
    // Квадратная матрица для умножения
    int sqItems[] = {1, 2, 3, 4};
    Matrix<int> m5(2, 2, sqItems);
    Matrix<int> m6(2, 2, sqItems);
    Matrix<int> m7 = m5.Multiply(m6);
    cout << "Square matrix multiplication result:" << endl;
    m7.Print();
    
    // Тест операторов
    Matrix<int> m8 = m5 + m6;
    cout << "Operator+ result:" << endl;
    m8.Print();
    
    Matrix<int> m9 = m5 * 3;
    cout << "Operator* scalar result:" << endl;
    m9.Print();
    
    Matrix<int> m10 = m5 * m6;
    cout << "Operator* matrix result:" << endl;
    m10.Print();
    
    cout << "Access via operator(): " << m5(0, 1) << endl;
    m5(0, 1) = 99;
    cout << "After operator() assignment: " << m5(0, 1) << endl;
}

// Главное меню
void ShowMenu() {
    cout << "\n========== LAB 3: QUEUE, STACK, DEQUE, MATRIX ==========" << endl;
    cout << "1. Test DynamicArray" << endl;
    cout << "2. Test LinkedList" << endl;
    cout << "3. Test ArraySequence" << endl;
    cout << "4. Test ListSequence" << endl;
    cout << "5. Test ImmutableArraySequence" << endl;
    cout << "6. Test Queue" << endl;
    cout << "7. Test Stack" << endl;
    cout << "8. Test Deque" << endl;
    cout << "9. Test Matrix" << endl;
    cout << "10. Run all tests" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose option: ";
}

int main() {
    int choice;
    
    do {
        ShowMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                DemoDynamicArray();
                break;
            case 2:
                DemoLinkedList();
                break;
            case 3:
                DemoArraySequence();
                break;
            case 4:
                DemoListSequence();
                break;
            case 5:
                DemoImmutableArraySequencefast();
                break;
            case 6:
                DemoQueue();
                break;
            case 7:
                DemoStack();
                break;
            case 8:
                DemoDeque();
                break;
            case 9:
                DemoMatrix();
                break;
            case 10:
                RunAllTests();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (choice != 0);
    
    return 0;
}