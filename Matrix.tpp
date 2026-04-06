#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <iostream>
#include <cmath>
#include <algorithm>
#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }
    
    data = DynamicArray<DynamicArray<T>>(rows);
    for (int i = 0; i < rows; i++) {
        data.Set(i, DynamicArray<T>(cols));
    }
}

template <class T>
Matrix<T>::Matrix(int rows, int cols, T* items) : rows(rows), cols(cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }
    if (items == nullptr) {
        throw std::invalid_argument("Items array is null");
    }
    
    data = DynamicArray<DynamicArray<T>>(rows);
    for (int i = 0; i < rows; i++) {
        DynamicArray<T> row(cols);
        for (int j = 0; j < cols; j++) {
            row.Set(j, items[i * cols + j]);
        }
        data.Set(i, row);
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
    data = DynamicArray<DynamicArray<T>>(rows);
    for (int i = 0; i < rows; i++) {
        data.Set(i, other.data.Get(i));
    }
}

template <class T>
T Matrix<T>::Get(int row, int col) const {
    return data.Get(row).Get(col);
}

template <class T>
void Matrix<T>::Set(int row, int col, T value) {
    data.Get(row).Set(col, value);
}

template <class T>
int Matrix<T>::GetRows() const {
    return rows;
}

template <class T>
int Matrix<T>::GetCols() const {
    return cols;
}

template <class T>
Matrix<T> Matrix<T>::Add(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data.Get(i).Set(j, data.Get(i).Get(j) + other.data.Get(i).Get(j));
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::MultiplyByScalar(T scalar) const {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data.Get(i).Set(j, data.Get(i).Get(j) * scalar);
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::Multiply(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
    }
    
    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            T sum = T();
            for (int k = 0; k < cols; k++) {
                sum = sum + data.Get(i).Get(k) * other.data.Get(k).Get(j);
            }
            result.data.Get(i).Set(j, sum);
        }
    }
    return result;
}

template <class T>
double Matrix<T>::Norm() const {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += data.Get(i).Get(j) * data.Get(i).Get(j);
        }
    }
    return std::sqrt(sum);
}

template <class T>
void Matrix<T>::SwapRows(int row1, int row2) {
    if (row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    if (row1 == row2) return;
    
    DynamicArray<T> temp = data.Get(row1);
    data.Set(row1, data.Get(row2));
    data.Set(row2, temp);
}

template <class T>
void Matrix<T>::MultiplyRow(int row, T scalar) {
    if (row < 0 || row >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    for (int j = 0; j < cols; j++) {
        data.Get(row).Set(j, data.Get(row).Get(j) * scalar);
    }
}

template <class T>
void Matrix<T>::AddRowToRow(int sourceRow, int targetRow, T scalar) {
    if (sourceRow < 0 || sourceRow >= rows || targetRow < 0 || targetRow >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    for (int j = 0; j < cols; j++) {
        T newValue = data.Get(targetRow).Get(j) + data.Get(sourceRow).Get(j) * scalar;
        data.Get(targetRow).Set(j, newValue);
    }
}

template <class T>
void Matrix<T>::SwapCols(int col1, int col2) {
    if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) {
        throw std::out_of_range("Column index out of range");
    }
    if (col1 == col2) return;
    
    for (int i = 0; i < rows; i++) {
        T temp = data.Get(i).Get(col1);
        data.Get(i).Set(col1, data.Get(i).Get(col2));
        data.Get(i).Set(col2, temp);
    }
}

template <class T>
void Matrix<T>::MultiplyCol(int col, T scalar) {
    if (col < 0 || col >= cols) {
        throw std::out_of_range("Column index out of range");
    }
    for (int i = 0; i < rows; i++) {
        data.Get(i).Set(col, data.Get(i).Get(col) * scalar);
    }
}

template <class T>
void Matrix<T>::AddColToCol(int sourceCol, int targetCol, T scalar) {
    if (sourceCol < 0 || sourceCol >= cols || targetCol < 0 || targetCol >= cols) {
        throw std::out_of_range("Column index out of range");
    }
    for (int i = 0; i < rows; i++) {
        T newValue = data.Get(i).Get(targetCol) + data.Get(i).Get(sourceCol) * scalar;
        data.Get(i).Set(targetCol, newValue);
    }
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    return Add(other);
}

template <class T>
Matrix<T> Matrix<T>::operator*(T scalar) const {
    return MultiplyByScalar(scalar);
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    return Multiply(other);
}

template <class T>
T& Matrix<T>::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    // Временное решение: возвращаем ссылку через статическую переменную
    static T temp;
    temp = data.Get(row).Get(col);
    return temp;
}

template <class T>
const T& Matrix<T>::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    static T temp;
    temp = data.Get(row).Get(col);
    return temp;
}

template <class T>
void Matrix<T>::Print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data.Get(i).Get(j) << " ";
        }
        std::cout << std::endl;
    }
}

template class Matrix<int>;
template class Matrix<double>;

#endif