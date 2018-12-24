//
// Created by Daniel Santos on 2/27/18.
//

#ifndef DSTRUCTS_FUNCTIONAL_H
#define DSTRUCTS_FUNCTIONAL_H

#include <functional>

template <class C, class T>
class Functional {
public:
  Functional() = default;
//  virtual ~Functional() = default;

  virtual void forEach(std::function<void(const T&)> f) const = 0;

  template <class S>
  C map(std::function<S(const T&)> t);

  virtual C filter(std::function<bool(const T&)> pred) const = 0;

  template <class S>
  S fold(const S&, const T&, std::function<S(const S&, const T&)>);

};

#endif //DSTRUCTS_FUNCTIONAL_H
