#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main() {
 bSearchTreeType<int> treeRoot;

  treeRoot.insert(78);
  treeRoot.insert(32);
  treeRoot.insert(89);
  treeRoot.insert(46);
  treeRoot.insert(28);
  treeRoot.insert(60);
  treeRoot.insert(98);
  treeRoot.insert(53);

  cout << endl << "Tree nodes in inorder: ";
  treeRoot.inorderTraversal();

  cout << endl << "Tree nodes in preorder: ";
  treeRoot.preorderTraversal();

  cout << endl << "Tree nodes in postorder: ";
  treeRoot.postorderTraversal();
  cout << endl;

  cout << "Tree Height: " << treeRoot.treeHeight() << endl;

  cout << "Number or Nodes: " << treeRoot.treeNodeCount() << endl;
  cout << "Number or Leaves: " << treeRoot.treeLeavesCount() << endl;

  return 0;
}