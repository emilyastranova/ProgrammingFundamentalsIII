#include <fstream>
#include <iostream>
#include "graphType.h"

using namespace std;

int main() {
  
  graphType myGraph;
  myGraph.createGraph();
  cout << "Depth First Traversal: " << endl;
  myGraph.depthFirstTraversal();
  cout << "\nBreadth First Traversal: " << endl;
  myGraph.breadthFirstTraversal();

  return 0;
}