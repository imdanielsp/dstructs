//
// Created by Daniel Santos on 8/5/18.
//

#ifndef DSTRUCTS_HEAP_HPP
#define DSTRUCTS_HEAP_HPP

#include <memory>
#include <algorithm>
#include <cmath>
#include <exception>
#include <initializer_list>

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
  _Heap<T, Comp>() : _heapSize(0) {}

  _Heap<T, Comp>(std::initializer_list<T> list) : _heapSize(0)
  {
    for (const auto item : list)
    {
      _buffer.push_back(item);
    }

    auto mid = static_cast<std::size_t>(std::floor(_buffer.size() / 2));
    for (std::size_t i = mid; i > 0; i--)
      _heapify(i);
  }

  ~_Heap<T, Comp>() = default;

  const T &top() const
  {
    return _buffer.at(0);
  }

  void insert(const T &item)
  {
    _buffer.push_back(item);
    _heapify();
  }

  void pop()
  {
    if (_buffer.size() == 0)
      throw std::out_of_range("Root is empty!");

    if (_buffer.size() > 1)
    {
      _buffer = _buffer.at(1);
    }

    _heapify();
  }

  void forEach(std::function<void(const T &)> f) const override
  {
    for (std::size_t i = 0; i < _buffer.size(); i++)
      f(_buffer.at(i));
  }

protected:
  void insert(_Heap<T, Comp> &cont, const T &it) override
  {
    cont.insert(it);
  }

private:
  const T &_parent(std::size_t idx) const
  {
    return _buffer.at(idx / 2);
  }

  const T &_left(std::size_t idx) const
  {
    return _buffer.at(2 * idx + 1);
  }

  const T &_right(std::size_t idx) const
  {
    return _buffer.at(2 * idx + 2);
  }

  void _heapify(std::size_t curr = 0)
  {
    std::sort(_buffer.begin(), _buffer.end());

    for (std::size_t i = 0; i < _buffer.size(); i++)
    {
      std::size_t left = 2 * i + 1;
      std::size_t right = 2 * i + 2;

      auto t = _buffer[i];
      if (left < _buffer.size())
      {
        _buffer[i] = _buffer[left];
        _buffer[left] = t;
      }

      if (right < _buffer.size())
      {
        _buffer[i] = _buffer[right];
        _buffer[right] = t;
      }
    }
  }

private:
  Comp _comp;
  std::vector<T> _buffer;
  std::size_t _heapSize;
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
