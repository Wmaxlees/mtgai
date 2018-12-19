/**
 * @Author: W. Max Lees
 * @Date:   2018-12-18T12:31:30-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-18T17:16:09-07:00
 */

#include <algorithm>
#include <array>
#include <memory>
#include <iostream>

#include "Matrix.h"

template <class T>
Matrix<T>::Matrix () {
  this->m_Width = 0;
  this->m_Height = 0;
  this->m_Assigned = 0;
}

template <class T>
Matrix<T>::~Matrix () {}

template <class T>
void Matrix<T>::put (std::unique_ptr<T[]> data, int length) {
  ++this->m_Height;

  if (this->m_Width == 0) {
    this->m_Width = length;
  } else if (this->m_Width != length) {
    throw -1;
  }

  if (this->m_Assigned < this->m_Height) {
    if (this->m_Data) {
      std::unique_ptr<T[]> tempArray = move(this->m_Data);
      this->m_Data = std::make_unique<T[]>((Matrix::EXPANSION_SIZE+this->m_Assigned) * this->m_Width);
      std::copy(&(tempArray[0]), &(tempArray[this->index(this->m_Height-2, this->m_Width)]), &(this->m_Data[0]));
      tempArray = nullptr;

      this->m_Assigned += Matrix::EXPANSION_SIZE;

    } else {
      this->m_Data = std::make_unique<T[]>((Matrix::EXPANSION_SIZE+this->m_Assigned) * this->m_Width);
    }
  }

  std::copy(data, data+(sizeof(T)*length), &(this->m_Data[this->index(this->m_Height-1, 0)]));
}

template <class T>
void Matrix<T>::append (const Matrix<T>* const other) {
  std::cout << "Combining: " << this->m_Width << " and " << other->m_Width << std::endl;

  if (this->m_Width == 0 && other->m_Width != 0) {
    std::cout << "Only other has data." << std::endl;
    this->m_Data = std::make_unique<T[]>(other->m_Assigned * other->m_Width);
    std::copy(&(other->m_Data[0]), &(other->m_Data[other->index(other->m_Height-1, other->m_Width)]), &(this->m_Data[0]));
    return;
  }

  if (other->m_Width == 0) {
    return;
  }

  if (this->m_Width != other->m_Width) {
    throw -1;
  }

  std::unique_ptr<T[]> tempArray = move(this->m_Data);

  std::size_t newSize = this->m_Assigned * this->m_Width;
  newSize += other->m_Assigned * this->m_Width;
  newSize += Matrix::EXPANSION_SIZE * this->m_Width;
  this->m_Data = std::make_unique<T[]>(newSize);

  for (std::size_t idx = 0; idx < this->m_Assigned * this->m_Width; ++idx) {
    this->m_Data[idx] = tempArray[idx];
  }

  for (std::size_t idx = this->m_Assigned * this->m_Width; idx <  (this->m_Assigned * this->m_Width) + (other->m_Assigned * this->m_Width); ++idx) {
    this->m_Data[idx] = other->m_Data[idx];
  }

}

template <class T>
void Matrix<T>::addColumn (T columnValue) {
  ++this->m_Width;

  std::unique_ptr<T[]> tempArray = move(this->m_Data);
  this->m_Data = std::make_unique<T[]>((Matrix::EXPANSION_SIZE+this->m_Assigned) * this->m_Width);

  for (unsigned int row = 0; row < this->m_Height; ++row) {
    for (unsigned int col = 0; col < this->m_Width-1; ++col) {
      this->m_Data[this->index(row, col)] = tempArray[this->index(row, col) - row];
    }
    this->m_Data[this->index(row, this->m_Width-1)] = columnValue;
  }

  ++this->m_Width;
}

template <class T>
std::size_t Matrix<T>::index (std::size_t row, std::size_t col) const {
  return row + this->m_Width * col;
}

template <class T>
const T& Matrix<T>::operator [] (std::size_t i) const {
  return this->m_Data[i];
}

template <class T>
T& Matrix<T>::operator [] (std::size_t i) {
  return this->m_Data[i];
}

template class Matrix<unsigned char>;
