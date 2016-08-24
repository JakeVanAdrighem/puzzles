/* PROBLEM: Print the nodes in a boundary traversal of a binary tree. */
// EXAMPLE: 
//                      23
//              /               \
//            10                 41
//        /        \          /     \
//       3         18        30      54
//    /     \    /   \     /    \   /   \
//   1       4  12    19  28    38 51   70
// Printout for in-order traversal:
// 23 10 3 1 4 12 19 28 38 51 70 54 41

// Print the in-order boundary traversal of a binary tree
struct *node {
  node *left;
  node *right;
  int val;
};

void printBoundaryTraversal(node *root) {
  if (root == null)
    return;
  cur = root;
  // print all left edge nodes excluding the leftmost leaf node
  while (cur->left) {
    printf("%i\n", cur->val);
    cur = cur->left;
  }

  // print all leaf nodes
  // TODO

  // print all right edge nodes excluding the rightmost leaf node
  while (cur->right) {
    printf("%i\n", cur->val);
    cur = cur->right;
  }
}
