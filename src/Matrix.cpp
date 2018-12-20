/**
 * @Author: W. Max Lees
 * @Date:   2018-12-18T12:31:30-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-20T14:25:35-07:00
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <memory>

#include "Matrix.h"

template <class T, std::size_t W>
Matrix<T, W>::Matrix () {
  this->m_Height = 0;
  this->m_Assigned = 0;
}

template <class T, std::size_t W>
Matrix<T, W>::~Matrix () {}

template <class T, std::size_t W>
void Matrix<T, W>::put (const std::array<T, W>& data) {
  ++this->m_Height;

  if (this->m_Assigned < this->m_Height) {
    if (this->m_Data) {
      std::unique_ptr<T[]> tempArray = move(this->m_Data);
      this->m_Data = std::make_unique<T[]>((Matrix::EXPANSION_SIZE+this->m_Assigned) * W);
      std::copy(&(tempArray[0]), &(tempArray[this->index(this->m_Height-2, W)]), &(this->m_Data[0]));

      this->m_Assigned += Matrix::EXPANSION_SIZE;

    } else {
      this->m_Data = std::make_unique<T[]>(Matrix::EXPANSION_SIZE * W);
    }
  }

  std::copy(data.cbegin(), data.cend(), &(this->m_Data[this->index(this->m_Height-1, 0)]));
}

template <class T, std::size_t W>
void Matrix<T, W>::append (std::unique_ptr<Matrix<T, W>>& other) {
  std::unique_ptr<T[]> tempArray = move(this->m_Data);

  std::size_t newSize = this->m_Assigned * W;
  newSize += other->m_Assigned * W;
  newSize += Matrix::EXPANSION_SIZE * W;
  this->m_Data = std::make_unique<T[]>(newSize);

  for (std::size_t idx = 0; idx < this->m_Height * W; ++idx) {
    this->m_Data[idx] = tempArray[idx];
  }

  for (std::size_t idx = 0; idx < other->m_Height * W; ++idx) {
    this->m_Data[idx + (this->m_Height * W)] = other->m_Data[idx];
  }

  this->m_Height = this->m_Height + other->m_Height;
  this->m_Assigned = newSize;
}

template <class T, std::size_t W>
std::size_t Matrix<T, W>::index (std::size_t row, std::size_t col) const {
  return row * W + col;
}

template <class T, std::size_t W>
const T& Matrix<T, W>::operator [] (std::size_t i) const {
  return this->m_Data[i];
}

template <class T, std::size_t W>
T& Matrix<T, W>::operator [] (std::size_t i) {
  return this->m_Data[i];
}

template class Matrix <unsigned char, 12>;
