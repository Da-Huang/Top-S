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
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> ans;
  while (root) {
    TreeNode *lr = root->left;
    if (lr) {
      while (lr->right && lr->right != root) lr = lr->right;
      if (lr->right) {
        lr->right = NULL;
        root = root->right;
      } else {
        lr->right = root;
        ans.push_back(root->val);
        root = root->left;
      }
    } else {
      ans.push_back(root->val);
      root = root->right;
    }
  }
  return ans;
}
