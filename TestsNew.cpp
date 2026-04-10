#include <iostream>
#include <cmath>
#include "Tests.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "Matrix.h"

using namespace std;

// ==================== НОВЫЕ ТЕСТЫ QUEUE ====================

bool TestQueue() {
    // Тест создания
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    if (q1.GetSize() != 3) return false;
    if (q1.Peek() != 1) return false;
    
    // Тест Enqueue/Dequeue
    Queue<int> q2;
    q2.Enqueue(10);
    q2.Enqueue(20);
    q2.Enqueue(30);
    if (q2.GetSize() != 3) return false;
    if (q2.Dequeue() != 10) return false;
    if (q2.Dequeue() != 20) return false;
    if (q2.GetSize() != 1) return false;
    
    // Тест исключений
    Queue<int> q3;
    try {
        q3.Dequeue();
        return false;
    } catch (const out_of_range&) {}
    
    try {
        q3.Peek();
        return false;
    } catch (const out_of_range&) {}
    
    return true;
}

// ==================== НОВЫЕ ТЕСТЫ STACK ====================

bool TestStack() {
    // Тест создания
    int arr[] = {1, 2, 3};
    Stack<int> s1(arr, 3);
    if (s1.GetSize() != 3) return false;
    if (s1.Peek() != 3) return false;
    
    // Тест Push/Pop
    Stack<int> s2;
    s2.Push(10);
    s2.Push(20);
    s2.Push(30);
    if (s2.GetSize() != 3) return false;
    if (s2.Pop() != 30) return false;
    if (s2.Pop() != 20) return false;
    if (s2.GetSize() != 1) return false;
    
    // Тест исключений
    Stack<int> s3;
    try {
        s3.Pop();
        return false;
    } catch (const out_of_range&) {}
    
    return true;
}

// ==================== НОВЫЕ ТЕСТЫ DEQUE ====================

bool TestDeque() {
    // Тест PushFront/PushBack
    Deque<int> d1;
    d1.PushBack(10);
    d1.PushBack(20);
    d1.PushFront(5);
    d1.PushFront(1);
    
    if (d1.GetSize() != 4) return false;
    if (d1.Front() != 1) return false;
    if (d1.Back() != 20) return false;
    
    // Тест PopFront/PopBack
    if (d1.PopFront() != 1) return false;
    if (d1.PopBack() != 20) return false;
    if (d1.GetSize() != 2) return false;
    if (d1.Front() != 5) return false;
    if (d1.Back() != 10) return false;
    
    // Тест исключений
    Deque<int> d2;
    try {
        d2.PopFront();
        return false;
    } catch (const out_of_range&) {}
    
    return true;
}

// ==================== НОВЫЕ ТЕСТЫ MATRIX ====================

bool TestMatrix() {
    // Тест создания
    Matrix<int> m1(2, 3);
    if (m1.GetRows() != 2) return false;
    if (m1.GetCols() != 3) return false;
    
    // Тест Set/Get
    m1(0, 0) = 5;
    if (m1.Get(0, 0) != 5) return false;
    
    // Тест сложения
    int items1[] = {1, 2, 3, 4, 5, 6};
    int items2[] = {1, 1, 1, 1, 1, 1};
    Matrix<int> m2(2, 3, items1);
    Matrix<int> m3(2, 3, items2);
    Matrix<int> m4 = m2.Add(m3);
    if (m4.Get(0, 0) != 2) return false;
    if (m4.Get(1, 2) != 7) return false;
    
    // Тест умножения на скаляр
    Matrix<int> m5 = m2.MultiplyByScalar(2);
    if (m5.Get(0, 0) != 2) return false;
    if (m5.Get(1, 2) != 12) return false;
    
    // Тест умножения матриц
    int sq1[] = {1, 2, 3, 4};
    int sq2[] = {1, 0, 0, 1};
    Matrix<int> m6(2, 2, sq1);
    Matrix<int> m7(2, 2, sq2);
    Matrix<int> m8 = m6.Multiply(m7);
    if (m8(0, 0) != 1) return false;
    if (m8.Get(0, 1) != 2) return false;
    if (m8.Get(1, 0) != 3) return false;
    if (m8.Get(1, 1) != 4) return false;
    
    // Тест нормы
    int normItems[] = {3, 4};
    Matrix<int> m9(1, 2, normItems);
    double norm = m9.Norm();
    if (std::abs(norm - 5.0) > 0.001) return false;
    
    // Тест элементарных преобразований
    int swapItems[] = {1, 2, 3, 4};
    Matrix<int> m10(2, 2, swapItems);
    m10.SwapRows(0, 1);
    if (m10.Get(0, 0) != 3) return false;
    
    // Тест исключений
    try {
        m1.Get(5, 0);
        return false;
    } catch (const out_of_range&) {}
    
    try {
        Matrix<int> m11(0, 5);
        return false;
    } catch (const invalid_argument&) {}
    
    return true;
}
