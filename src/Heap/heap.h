/* *
 * MIT License
 *
 * Copyright (c) 2018 Daniel Santos
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

#ifndef DSTRUCTS_HEAP_HPP
#define DSTRUCTS_HEAP_HPP

#include <memory>
#include <algorithm>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <mutex>

#include "../Dynamic_Array/dynamic_array.h"
#include "../Functional/functional.h"

namespace DStructs
{

namespace Heap
{
template <typename K>
struct Max
{
  bool operator()(const K &left, const K &right)
  {
    return left >= right;
  }
};

template <typename K>
struct Min
{
  bool operator()(const K &left, const K &right)
  {
    return left <= right;
  }
};
} // namespace Heap

template <typename T, typename Comp>
class _Heap : public Functional<_Heap<T, Comp>, T>
{
public:
  _Heap<T, Comp>()
      : _heapSize(0),
        _bufferMutex(std::make_unique<std::mutex>())
  {
  }

  _Heap<T, Comp>(std::initializer_list<T> list)
      : _heapSize(list.size()),
        _buffer(list),
        _bufferMutex(std::make_unique<std::mutex>())
  {
    _buildHeap();
  }

  ~_Heap<T, Comp>() = default;

  // Non-copyable non-movable
  _Heap(_Heap &&) = delete;
  _Heap(const _Heap &) = delete;
  _Heap &operator=(_Heap &&) = delete;
  _Heap &operator=(const _Heap &) = delete;

  const T &top() const
  {
    std::scoped_lock lock(*_bufferMutex);
    return _buffer.at(0);
  }

  void insert(const T &item)
  {
    std::scoped_lock lock(*_bufferMutex);
    _buffer.push_back(item);
  }

  void pop()
  {
    if (_buffer.size() == 0)
      throw std::out_of_range("Root is empty!");

    std::scoped_lock lock(*_bufferMutex);
    _buffer.pop_back();
  }

  void forEach(std::function<void(const T &)> f) const override
  {
    std::scoped_lock lock(*_bufferMutex);
    for (std::size_t i = 0; i < _buffer.size(); i++)
      f(_buffer.at(i));
  }

protected:
  void insert(_Heap<T, Comp> &cont, const T &it) override
  {
    std::scoped_lock lock(*_bufferMutex);
    cont.insert(it);
  }

private:
  const std::size_t _parent(std::size_t idx) const
  {
    return std::floor(idx / 2);
  }

  const std::size_t _left(std::size_t idx) const
  {
    return 2 * idx + 1;
  }

  const std::size_t _right(std::size_t idx) const
  {
    return 2 * idx + 2;
  }

  void _buildHeap()
  {
    auto half = std::floor(_buffer.size() / 2);
    for (int i = half; i >= 0; i--)
    {
      _heapify(i);
    }
  }

  void _heapify(std::size_t curr)
  {
    auto left = _left(curr);
    auto right = _right(curr);
    std::size_t largest;
    if (left < _heapSize &&
        _comp(_buffer[left], _buffer[curr]))
    {
      largest = left;
    }
    else
    {
      largest = curr;
    }

    if (right < _heapSize &&
        _comp(_buffer[right], _buffer[curr]))
    {
      largest = right;
    }

    if (largest != curr)
    {
      std::swap(_buffer[curr], _buffer[largest]);
      _heapify(largest);
    }
  }

private:
  Comp _comp;
  std::unique_ptr<std::mutex> _bufferMutex;
  std::vector<T> _buffer;
  std::atomic<std::size_t> _heapSize;
};

template <typename T>
class MaxHeap : public _Heap<T, Heap::Max<T>>
{
public:
  MaxHeap<T>() : _Heap<T, Heap::Max<T>>() {}

  MaxHeap<T>(std::initializer_list<T> list) : _Heap<T, Heap::Max<T>>(list) {}
};

template <typename T>
class MinHeap : public _Heap<T, Heap::Min<T>>
{
public:
  MinHeap<T>() : _Heap<T, Heap::Min<T>>() {}

  MinHeap<T>(std::initializer_list<T> list) : _Heap<T, Heap::Min<T>>(list) {}
};

} // namespace DStructs

#endif //DSTRUCTS_HEAP_HPP
