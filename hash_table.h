#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>
#include <stdexcept>

template <typename K, typename V>
struct Hash_table
{
    K key;
    V value;

    Hash_table *nxt;

    Hash_table(const K &k, const V &v) : key(k), value(v), nxt(nullptr) {}
};

template <typename K, typename V>
class Hash_table
{
private:
    Hash_table<K, V> **table;
    int cap;
    int size;

    int get_indx(const K &key) const
    {
        return hashFunction(key) % cap;
    }

public:
    Hash_table(/* args */);
    ~Hash_table();

    void insert(const K &key, const V &val)
    {
        int indx = get_indx(key);
        Hash_table<K, V> *curr = table[indx];

        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                curr->val = val;
                return;
            }
            curr = curr->nxt;
        }
    }
};

#endif