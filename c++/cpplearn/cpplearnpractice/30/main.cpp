#include "unorderedmap.h"

int main(){
    MyHashMap<std::string, int> my_hashmap;
    my_hashmap.insert("apple", 3);
    my_hashmap.insert("banana", 2);
    for(auto it = my_hashmap.begin(); it != my_hashmap.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }
    my_hashmap.erase("banana");
    for(auto it = my_hashmap.begin(); it != my_hashmap.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}