vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == NULL) return ans;
  queue<TreeNode*> que;
  que.push(root);
  que.push(NULL);
  vector<int> v;
  while (!que.empty()) {
    TreeNode *node = que.front();
    que.pop();
    if (node == NULL) {
      ans.push_back(v);
      if (que.empty()) break;
      que.push(NULL);
      v.clear();
    } else {
      v.push_back(node->val);
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
  }
  return ans;
}
