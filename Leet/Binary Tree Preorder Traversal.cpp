// #redo
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> ans;
  if (root == NULL) return ans;
  stack<TreeNode*> stk;
  stk.push(root);
  while (!stk.empty()) {
    TreeNode *node = stk.top();
    stk.pop();
    ans.push_back(node->val);
    if (node->right) stk.push(node->right);
    if (node->left) stk.push(node->left);
  }
  return ans;
}

// #version2
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> res;
  TreeNode *ptr = root;
  while ( ptr ) {
    if ( ptr->left ) {
      TreeNode *q = ptr->left;
      while ( q->right && q->right != ptr ) q = q->right;
      if ( q->right == NULL ) {
        res.push_back(ptr->val);
        q->right = ptr;
        ptr = ptr->left;

      } else {
        q->right = NULL;
        ptr = ptr->right;
      }

    } else {
      res.push_back(ptr->val);
      ptr = ptr->right;
    }
  }
  return res;
}


