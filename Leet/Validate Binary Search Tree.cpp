// #redo
bool isValidBST(TreeNode* root) {
  stack<TreeNode*> stk;
  TreeNode *last = root;
  TreeNode *pre = NULL;
  while (last || !stk.empty()) {
    while (last) {
      stk.push(last);
      last = last->left;
    }
    TreeNode *node = stk.top();
    stk.pop();

    if (pre && pre->val >= node->val) return false;
    pre = node;

    last = node->right;
  }
  return true;
}


// #version2
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

