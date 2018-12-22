
#ifndef DSTRUCTS_HASH_TABLE_H
#define DSTRUCTS_HASH_TABLE_H

#include <functional>

#include "../Dynamic_Array/dynamic_array.h"
#include "../Linked_List/linked_list.h"


namespace DStructs {
  class KeyNotFound {};

  template <typename K, typename V>
  class Pair {
    public:
      Pair() {};

      Pair(const K& k, const V& v) : _key(k), _value(v) { }

      const K& key() const {
        return _key;
      }

      const V& value() const {
        return _value;
      }

      void set(const K& k, const V& v) {
        _key = k;
        _value = v;
      }

    private:
      K _key;
      V _value;
  };

  template <typename K,
            typename V,
            typename Hasher = std::hash<K>>
  class HashTable {
    public:
      HashTable() : _m(0) {}

      explicit HashTable(std::initializer_list<std::pair<K, V>> list) {

      }

      ~HashTable() {}

      Pair<K, V>& get(const K& k) {
        std::size_t key = _hasher(k) % _m;
        Pair<K, V>* p = nullptr;

        _table.at(key).forEach([key, &p](const Pair<K, V> pair) {
          if (pair.key == key) {
            *p = pair;
          }
        });

        for (int i = 0; i < _table.size(); i++) {
          
        }

        if (!p)
          throw new KeyNotFound();

        return *p;
      }

      void insert(const K& key, const V& item) {

      }

      void insert(const Pair<K, V>& p);

      void remove(const K& key);

      void update(const K& key, const V& new_item);

    private:
      Hasher _hasher;
      DynamicArray<LinkedList<Pair<K, V>>> _table;
      std::size_t _m;
  };
}

#endif // DSTRUCTS_HASH_TABLE_H