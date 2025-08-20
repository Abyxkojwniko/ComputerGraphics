#include "GraphNode.h"


int main(){
    auto graph = createGraph();
    for(auto& node : graph){
        node->printEdges();
    }
    return 0;
}