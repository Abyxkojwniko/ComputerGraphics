#pragma once

#include <iostream>
#include <vector>
#include <memory>

class GraphNode{
public:
    explicit GraphNode(int id);
    void addEdge(const std::shared_ptr<GraphNode>& node);
    void printEdges() const;
    
private:
    int _id;
    std::vector<std::weak_ptr<GraphNode>> _connections;
};

std::vector<std::shared_ptr<GraphNode>> createGraph();