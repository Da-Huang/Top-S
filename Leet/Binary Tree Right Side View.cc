vector<int> rightSideView(TreeNode* root) {
  vector<int> ans;
  if (root == NULL) return ans;
  TreeNode *last = NULL;
  queue<TreeNode*> que;
  que.push(root);
  que.push(NULL);
  while (!que.empty()) {
    TreeNode *node = que.front();
    que.pop();
    if (node == NULL) {
      ans.push_back(last->val);
      if (que.empty()) break;
      que.push(NULL);
    } else {
      last = node;
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
  }
  return ans;
}
