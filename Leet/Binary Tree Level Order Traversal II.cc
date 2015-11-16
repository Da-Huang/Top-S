vector<vector<int>> levelOrderBottom(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == NULL) return ans;

  vector<int> v;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node == NULL) {
      ans.push_back(v);
      v.clear();
      if (q.empty()) break;
      q.push(NULL);

    } else {
      v.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
