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

//  template <class S>
//  C<S> map(std::function<S(const T&)> t) {
//    C container;
//    forEach([&container, &t, this] (auto it) {
//      this->insert(container, t(it));
//    });
//    return container;
//  }

  C filter(std::function<bool(const T&)> pred) {
    C container;
    forEach([&container, &pred, this] (auto it) {
      if (pred(it)) {
        this->insert(container, it);
      }
    });
    return container;
  }

protected:
  virtual void insert(C& cont, const T& it) = 0;
};

#endif //DSTRUCTS_FUNCTIONAL_H
