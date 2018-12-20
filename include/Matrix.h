/**
 * @Author: W. Max Lees
 * @Date:   2018-12-18T12:26:36-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-19T16:18:47-07:00
 */

#pragma once

#ifndef _H_MATRIX
#define _H_MATRIX

#include <array>
#include <iostream>
#include <memory>

template <class T, std::size_t W>
class Matrix {
  public:
    Matrix ();
    ~Matrix ();

    const T& operator [](std::size_t i) const;
    T& operator [](std::size_t i);

    void put (const std::array<T, W>& data);
    void append (std::unique_ptr<Matrix<T, W>>& other);

    std::size_t index (std::size_t row, std::size_t col) const;

    friend std::ostream& operator<< (std::ostream& stream, const Matrix& matrix) {
      for (std::size_t row = 0; row < matrix.m_Height; ++row) {
        for (std::size_t col = 0; col < W; ++col) {
          stream << (unsigned int)matrix.m_Data[matrix.index(row, col)] << " | ";
        }
        stream << std::endl;
      }

      return stream;
    }

  protected:
    std::unique_ptr<T[]> m_Data;

    int m_Height;
    int m_Assigned;

  private:
    static const int EXPANSION_SIZE = 20;

};

#endif //_H_MATRIX
