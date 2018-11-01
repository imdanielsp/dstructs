/* *
 * MIT License
 *
 * Copyright (c) 2016 Daniel Santos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */
#ifndef DSTRUCTS_DYNAMIC_ARRAY_H
#define DSTRUCTS_DYNAMIC_ARRAY_H

#include <stdexcept>

namespace DStructs {
/**
 * \brief   A dynamic array is an array that doesn't have a fixed size like
 * regular arrays. The size of this dynamic array grow automatically at a
 * rate of 1.7 with an initial capacity of 4. If the size is greater than
 * half of the capacity, the array grow capcity * 1.7 + 1. For example, if an
 * array with a capacity of 4 and a size of 2 attempts to add another
 * element, the array dynamically grow to a capacity of 7.
 * */
template <class T>
class DynamicArray final {
 public:
  /**
   * \brief     This is a default constructor for the dynamic array. The
   * capacity of the array is initialized to four and allocates enough space
   * for this capacity.
   * */
  DynamicArray();
  /**
   * \brief     Deconstructor
   * */
  ~DynamicArray();
  /**
   * \brief     Insert an element at the end of the array in a constant time
   * using the subscript operator.
   *
   * \param     const T&
   * */
  void push_back(const T& data);
  /**
   * \brief     Returns an element at the given index if the index is less
   * than size - 1 and greater or equal 0.
   *
   * \param     std::size_t
   * \returns   T&
   * */
  const T& at(std::size_t idx) const;
  /**
   * \brief     Returns the current size of the array.
   *
   * \returns   std::size_t
   * */
  std::size_t size() const;
  /**
   * \brief     Returns the capacity of the current array.
   *
   * \returns   std::size_t
   * */
  std::size_t capacity() const;
  /**
   * \brief     Removes element at pos.
   *
   * \param     std::size_t position
   * */
  void remove(std::size_t pos);
  /**
   * \brief     This is the subscript operator that overloaded returns an
   * element of the array in constant time.
   *
   * \param     std::size_t
   *
   * \returns   T&
   * */
  T& operator[](std::size_t idx);

 private:
  /**
   * \brief     This is a helper function that increase the capacity of the
   * array by the given value.
   *
   * \param     const std::size_t
   * */
  void increase_capacity(const std::size_t new_capacity);
  T* buffer_;               //< array's buffer
  std::size_t capacity_;    //< holds capacity of the array
  std::size_t size_;        //< holds the size the array

};  // DYNAMIC ARRAY

} // NAMESPACE DSTRUCTS

#include "dynamic_array.cc"
#endif //DSTRUCTS_DYNAMIC_ARRAY_H
