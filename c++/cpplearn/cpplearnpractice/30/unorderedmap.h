#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <iterator>
#include <stdexcept>


template <typename Key, typename T>
struct HashNode{
    std::pair<Key, T> data;
    HashNode* next;
    HashNode(const Key& key, const T& value):data(std::make_pair(key, value)), next(nullptr){};
};

template<typename Key, typename T, typename Hash = std::hash<Key>>
class MyHashMap{
public:
    using key_type = key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;
    class Iterator{
    public:
        
    private:
        MyHashMap* _map;
        
    }
private:
    std::vector<HashNode<Key, T>*> _buckets;
    size_type _bucket_count;
    size_type _element_count;
    double _max_load_factor;
    Hash _hash_func;
    void rehash();
};