#include "ResourceManager.h"

ResourceManager::ResourceManager(int value):
    resource_(std::make_unique<int>(value)){}

int ResourceManager::getValue() const{
    return *resource_;
}

void ResourceManager::setValue(int value){
    *resource_ = value;
}