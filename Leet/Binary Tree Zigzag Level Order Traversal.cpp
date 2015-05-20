// #redo
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == NULL) return ans;

  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  vector<int> v;
  bool isReverse = false;
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node == NULL) {
      if (isReverse) reverse(v.begin(), v.end());
      isReverse = !isReverse;
      ans.push_back(v);
      v.clear();
      if (!q.empty()) q.push(NULL);

    } else {
      v.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }
  return ans;
}
