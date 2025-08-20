#pragma once
#include <memory>
#include <iostream>


class ResourceManager{
public:
    explicit ResourceManager(int value);
    int getValue() const;
    void setValue(int value);
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager &&) = default;
    ResourceManager& operator=(ResourceManager &&) = default;
private:
    std::unique_ptr<int> resource_;
};