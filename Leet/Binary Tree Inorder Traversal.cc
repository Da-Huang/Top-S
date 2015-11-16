// #redo
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> ans;
  stack<TreeNode*> stk;
  TreeNode *rl = root;
  while (rl || !stk.empty()) {
    while (rl) {
      stk.push(rl);
      rl = rl->left;
    }
    TreeNode *node = stk.top();
    stk.pop();
    ans.push_back(node->val);

    rl = node->right;
  }
  return ans;
}


// #version2
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> ans;
  while (root) {
    TreeNode *l = root->left;
    if (l) {
      while (l->right && l->right != root) l = l->right;
      if (l->right) {
        l->right = NULL;

      } else {
        l->right = root;
        root = root->left;
        continue;
      }
    }
    ans.push_back(root->val);
    root = root->right;
  }
  return ans;
}
