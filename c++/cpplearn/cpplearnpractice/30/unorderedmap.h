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
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;

    MyHashMap(size_type initial_capacity = 16, double max_load_factor = 0.75):
    _bucket_count(initial_capacity), _element_count(0), _max_load_factor(max_load_factor), _hash_func(Hash()){
        _buckets.resize(_bucket_count);
    }
    ~MyHashMap(){
        clear();
    }

    MyHashMap(const MyHashMap& other) = delete;
    MyHashMap& operator=(const MyHashMap& other) = delete;

    void insert(const Key& key, const T& value){
        size_type hash_value = _hash_func(key);
        size_type index = hash_value % _bucket_count;
        auto * node = _buckets[index];
        while(node != nullptr){
            if(node->data.first == key){
                node->data.second = value;
                return ;
            }
            node = node->next;
        }
        auto new_node = new HashNode<Key, T>(key, value);
        new_node->next = _buckets[index];
        _buckets[index] = new_node;
        ++_element_count;
        auto load_factor = static_cast<double>(_element_count) / _bucket_count;
        if(load_factor > _max_load_factor){
            rehash();
        }
    };
    T* find(const Key& key) const{
        auto index = _hash_func(key) % _bucket_count;
        auto* node = _buckets[index];
        while(node != nullptr){
            if(node->data.first == key){
                return &(node->data.second);
            }
            node = node->next;
        }
        return nullptr;
    }
    void clear(){
        for(size_type i = 0; i < _buckets.size(); ++i){
            HashNode<Key, T>* current_node  = _buckets[i];
            while(current_node != nullptr){
                HashNode<Key, T>* temp = current_node;
                current_node = current_node->next;
                delete temp;
            }
            _buckets[i] = nullptr;
        }
        _element_count = 0;
    }
    bool erase(const Key& key){
        auto index = _hash_func(key) % _bucket_count;
        auto* node = _buckets[index];
        HashNode<Key, T>* prev = nullptr;
        while(node != nullptr){
            if(node->data.first == key){
                if(prev == nullptr){
                    _buckets[index] = node->next;
                }
                else{
                    prev->next = node->next;
                }
                delete node;
                --_element_count;
                return true;
            }
            prev = node;
            node = node->next;
        }
        return false;
    }
    size_type size() const{
        return _element_count;
    }
    bool empty() const{
        return _element_count == 0;
    }

    class Iterator{
    public:
        using Iterator_category = std::forward_iterator_tag;
        using value_type = std::pair<Key, T>;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(MyHashMap* map, size_type bucket_index, HashNode<Key, T>* node):
        _map(map), _bucket_index(bucket_index), _current_node(node){

        }
        reference operator*() const{
            if(_current_node == nullptr){
                throw std::out_of_range("Iterator out of range");
            }
            return _current_node->data;
        }
        pointer operator->() const{
            if(_current_node == nullptr){
                throw std::out_of_range("Iterator out of range");
            }
            return &(_current_node->data);
        }

        Iterator& operator++(){
            advance();
            return *this;
        }
        Iterator operator++(int){
            Iterator temp = *this;
            advance();
            return temp;
        }
        
        bool operator==(const Iterator& other) const{
            return _map == other._map && _bucket_index == other._bucket_index && _current_node == other._current_node;
        }
        bool operator!=(const Iterator& other) const{
            return !(*this == other);
        }

    private:
        MyHashMap* _map;
        size_type _bucket_index;
        HashNode<Key, T>* _current_node;
        void advance(){
            if(_current_node != nullptr){
                _current_node = _current_node->next;
            }
           while(_current_node == nullptr){
               if(_bucket_index +1  < _map->_bucket_count){
                   ++_bucket_index;
                   _current_node = _map->_buckets[_bucket_index];
               }else if(_bucket_index +1  == _map->_bucket_count){
                   ++_bucket_index;
                   break;
               }
           }
        }
    };
    Iterator begin(){
        for(size_type i = 0; i < _bucket_count; ++i){
            if(_buckets[i] != nullptr){
                return Iterator(this, i, _buckets[i]);
                }
            }
        return end();
    };
    Iterator end(){
        return Iterator(this, _bucket_count, nullptr);
    };
private:
    std::vector<HashNode<Key, T>*> _buckets;
    size_type _bucket_count;
    size_type _element_count;
    double _max_load_factor;
    Hash _hash_func;
    void rehash(){
        size_type new_bucket_count = _bucket_count * 2;
        std::vector<HashNode<Key, T>*> new_buckets(new_bucket_count, nullptr);
        for(size_type i = 0; i < _bucket_count; ++i){
            auto *node = _buckets[i];
            while(node != nullptr){
                auto *next_node = node->next;
                auto new_index = _hash_func(node->data.first) % new_bucket_count;
                node->next = new_buckets[new_index];
                new_buckets[new_index] = node;
                node = next_node;
            }
        }
        _buckets = std::move(new_buckets);
        _bucket_count = new_bucket_count;
    }
};