#include <iostream>
#include "Tests.h"

using namespace std;

// ==================== ТЕСТЫ DYNAMIC ARRAY ====================

bool TestDynamicArrayCreation() {
    // Тест 1: создание из массива
    int arr1[] = {1, 2, 3, 4, 5};
    DynamicArray<int> da1(arr1, 5);
    
    if (da1.GetSize() != 5) return false;
    for (int i = 0; i < 5; i++) {
        if (da1.Get(i) != arr1[i]) return false;
    }
    
    // Тест 2: создание пустого массива
    DynamicArray<int> da2(0);
    if (da2.GetSize() != 0) return false;
    
    // Тест 3: копирующий конструктор
    DynamicArray<int> da3(da1);
    if (da3.GetSize() != 5) return false;
    for (int i = 0; i < 5; i++) {
        if (da3.Get(i) != da1.Get(i)) return false;
    }
    
    return true;
}

bool TestDynamicArrayGetSet() {
    int arr[] = {10, 20, 30};
    DynamicArray<int> da(arr, 3);
    
    // Тест Get
    if (da.Get(0) != 10) return false;
    if (da.Get(1) != 20) return false;
    if (da.Get(2) != 30) return false;
    
    // Тест Set
    da.Set(1, 99);
    if (da.Get(1) != 99) return false;
    
    return true;
}

bool TestDynamicArrayResize() {
    int arr[] = {1, 2, 3};
    DynamicArray<int> da(arr, 3);
    
    // Увеличение размера
    da.Resize(5);
    if (da.GetSize() != 5) return false;
    if (da.Get(0) != 1 || da.Get(1) != 2 || da.Get(2) != 3) return false;
    
    // Уменьшение размера
    da.Resize(2);
    if (da.GetSize() != 2) return false;
    if (da.Get(0) != 1 || da.Get(1) != 2) return false;
    
    return true;
}

bool TestDynamicArrayExceptions() {
    int arr[] = {1, 2, 3};
    DynamicArray<int> da(arr, 3);
    
    // Тест выброса исключения при Get с отрицательным индексом
    try {
        da.Get(-1);
        return false;
    } catch (const out_of_range&) {
        // OK
    }
    
    // Тест выброса исключения при Get с индексом >= размера
    try {
        da.Get(3);
        return false;
    } catch (const out_of_range&) {
        // OK
    }
    
    // Тест выброса исключения при Set с неверным индексом
    try {
        da.Set(5, 100);
        return false;
    } catch (const out_of_range&) {
        // OK
    }
    
    return true;
}