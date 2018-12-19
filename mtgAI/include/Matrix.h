/**
 * @Author: W. Max Lees
 * @Date:   2018-12-18T12:26:36-07:00
 * @Email:  william.lees@nist.gov
 * @Last modified by:   W. Max Lees
 * @Last modified time: 2018-12-18T17:16:24-07:00
 */

#pragma once

#ifndef _H_MATRIX
#define _H_MATRIX

#include <memory>

template <class T>
class Matrix {
  public:
    Matrix ();
    ~Matrix ();

    const T& operator [](std::size_t i) const;
    T& operator [](std::size_t i);

    void put (std::unique_ptr<T[]> data, int length);
    void append (const Matrix<T>* const other);
    void addColumn (T columnValue);

    std::size_t index (std::size_t row, std::size_t col) const;

  protected:
    std::unique_ptr<T[]> m_Data;

    int m_Width;
    int m_Height;
    int m_Assigned;

  private:
    static const int EXPANSION_SIZE = 20;

};

#endif //_H_MATRIX
