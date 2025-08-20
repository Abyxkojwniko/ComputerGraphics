#include "GraphNode.h"

GraphNode::GraphNode(int id):
    _id(id){}

void GraphNode::addEdge(const std::shared_ptr<GraphNode>& node){
    _connections.push_back(node);
}

void GraphNode::printEdges() const{
    std::cout << "Node " << _id << " connect to ";
    for(auto& node : _connections){
        if(auto sp = node.lock()){
            std::cout << sp->_id <<" ";
        }
    }
    std::cout << std::endl;
}

std::vector<std::shared_ptr<GraphNode>> createGraph(){
    auto node1 = std::make_shared<GraphNode>(1);
    auto node2 = std::make_shared<GraphNode>(2);
    auto node3 = std::make_shared<GraphNode>(3);
    auto node4 = std::make_shared<GraphNode>(4);

    node1->addEdge(node2);
    node2->addEdge(node3);
    node3->addEdge(node4);
    node4->addEdge(node1);

    return {node1, node2, node3, node4};
}