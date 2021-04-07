#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include "Assignment-1.h"
#include "Test1.h"
using namespace std;

set<Node> visited;
vector<Node> path;

/// TODO: print each path once this method is called, and
/// add each path as a string into std::set<std::string> paths
/// Print the path in the format "START: 1->2->4->5->END", where -> indicate an edge connects two node IDs
void GraphTraversal::printPath(std::vector<const Node *> &path)
{   
    string str = "START: ";    
    for (const Node *n : path){        
        str = str + to_string(n->getNodeID()) + "->";    
    }    
    str = str + "END";    
    cout << str << endl;    
    paths.insert(str);
};

/// TODO: Implement your depth first search here to traversal each program path (once for any loop) from src to dst
void GraphTraversal::DFS(set<const Node *> &visited, vector<const Node *> &path, const Node *src, const Node *dst)
{
    visited.insert(src);
    path.push_back(src);    
    
    if (src == dst)
        printPath(path);

    
     for (const Edge *e : src->getOutEdges())
         if (visited.find(e->getDst()) == visited.end())            
            DFS(visited, path, e->getDst(), dst);
            
    visited.erase(src);    
    path.pop_back();
    
}

/// Entry of the program
int main()
{
    Test();
    return 0;
}