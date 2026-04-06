#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <cmath>

template <class T>
class Matrix {
private: //не должен быть массив массивов (sequence sequence)
    DynamicArray<DynamicArray<T>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, T* items);
    Matrix(const Matrix<T>& other);
    ~Matrix() = default;

    T Get(int row, int col) const;
    void Set(int row, int col, T value);
    int GetRows() const;
    int GetCols() const;

    // Арифметические операции
    Matrix<T> Add(const Matrix<T>& other) const;
    Matrix<T> MultiplyByScalar(T scalar) const;
    Matrix<T> Multiply(const Matrix<T>& other) const;

    // Вычисление нормы (евклидова)
    double Norm() const;

    // Элементарные преобразования строк
    void SwapRows(int row1, int row2);
    void MultiplyRow(int row, T scalar);
    void AddRowToRow(int sourceRow, int targetRow, T scalar = 1);

    // Элементарные преобразования столбцов
    void SwapCols(int col1, int col2);
    void MultiplyCol(int col, T scalar);
    void AddColToCol(int sourceCol, int targetCol, T scalar = 1);

    // Операторы
    Matrix<T> operator+(const Matrix<T>& other) const;//проверить есть ли лишнее копирование (куда возвращает копии)
    Matrix<T> operator*(T scalar) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    T& operator()(int row, int col);
    const T& operator()(int row, int col) const;

    // Для вывода
    void Print() const;
};

#include "Matrix.tpp"

#endif
