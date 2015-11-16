// #redo
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> ans;
  TreeNode *rl = root;
  stack<TreeNode*> stk;
  TreeNode *last = NULL;
  while (rl || !stk.empty()) {
    while (rl) {
      stk.push(rl);
      rl = rl->left;
    }
    TreeNode *node = stk.top();
    if (node->right == NULL || node->right == last) {
      stk.pop();
      ans.push_back(node->val);
      last = node;
    } else rl = node->right;
  }
  return ans;
}


// #version2
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> ans;
  TreeNode ROOT(0);
  ROOT.left = root;
  root = &ROOT;
  while (root) {
    TreeNode *lr = root->left;
    if (lr) {
      while (lr->right && lr->right != root) lr = lr->right;
      if (lr->right) {
        lr->right = NULL;
        TreeNode *head = root->left, *tail = root->left;
        while (tail->right) {
          TreeNode *node = tail->right;
          tail->right = node->right;
          node->right = head;
          head = node;
        }
        tail = head;
        ans.push_back(tail->val);
        while (tail->right) {
          TreeNode *node = tail->right;
          ans.push_back(node->val);
          tail->right = node->right;
          node->right = head;
          head = node;
        }
      } else {
        lr->right = root;
        root = root->left;
        continue;
      }
    }
    root = root->right;
  }
  return ans;
}
