#include <unordered_map>
#include <string>
#include "unordermap.h"

int main(){
    std::unordered_map<std::string, int> umap;
    std::unordered_map<std::string, int> umap_init={
        {"apple", 1},
        {"banana", 200},
        {"pear", 10}
    };
    std::unordered_map<std::string, int> umap_from_map(umap_init);
    auto apple_cout = umap["apple"];
    std::cout << apple_cout << std::endl;
    umap.insert({"melon", 100});//拷贝构造
    umap.emplace("kiwi", 20);
    try{
        int banana_count = umap.at("banana");
    }catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    auto it = umap.find("melon");
    if(it == umap.end()){
        std::cout << "melon not found" << std::endl;
    }else{
        std::cout << "melon found" << std::endl;
    }
    umap.erase("melon");
    it = umap.find("melon");
    if(it == umap.end()){
        std::cout << "melon not found" << std::endl;
    }else{
        std::cout << "melon found" << std::endl;
    }
    for(auto it = umap.begin(); it != umap.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }
    std::cout << "=====================================================================" << std::endl;
    for(const auto& pair : umap_init){
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    std::cout << "=====================================================================" << std::endl;
    std::unordered_map<Point<int>, std::string, PointHash<int>> point_map;
    point_map[{1, 2}] = "A";
    point_map[{3, 4}] = "B";
    for(auto it = point_map.begin(); it != point_map.end(); ++it){
        std::cout << it->first << " : " << it->second << std::endl;
    }
    std::cout << "=====================================================================" << std::endl;
    std::unordered_map<Point<int>, std::string, PointHash<int>, PointEqual<int>> point_map2;
    
    return 0;
}