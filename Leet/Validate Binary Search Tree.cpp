// Solution 1
bool isValidBST(TreeNode *root) {
  stack<TreeNode*> nodeStack;
  while ( root ) {
    nodeStack.push(root);
    root = root->left;
  }
  TreeNode *last = NULL;

  while ( !nodeStack.empty() ) {
    TreeNode *node = nodeStack.top();
    nodeStack.pop();
    // visit node
    if ( last != NULL ) {
      if ( last->val >= node->val ) return false;
    }
    last = node;

    if ( node->right ) {
      node = node->right;
      while ( node ) {
        nodeStack.push(node);
        node = node->left;
      }
    }
  }
  return true;
}

// Solution 2
bool isValidBST(TreeNode *root) {
  TreeNode *last = NULL;
  TreeNode *ptr = root;
  bool res = true;
  while ( ptr ) {
    if ( ptr->left ) {
      TreeNode *q = ptr->left;
      while ( q->right && q->right != ptr ) q = q->right;
      if ( q->right == NULL ) {
        q->right = ptr;
        ptr = ptr->left;
        continue;

      } else {
        q->right = NULL;
      }
    }
    // visit ptr
    if ( last != NULL ) {
      if ( last->val >= ptr->val ) res = false;
    }
    last = ptr;
    ptr = ptr->right;
  }
  return res;
}

