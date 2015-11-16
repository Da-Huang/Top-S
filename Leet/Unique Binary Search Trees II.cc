vector<TreeNode*> __generateTrees(int start, int last) {
  vector<TreeNode*> ans;
  if (start > last) {
    ans.push_back(NULL);
    return ans;
  }
  for (int i = start; i <= last; ++ i) {
    auto leftAns = __generateTrees(start, i - 1);
    auto rightAns = __generateTrees(i + 1, last);
    for (TreeNode *left : leftAns) {
      for (TreeNode *right : rightAns) {
        TreeNode *node = new TreeNode(i);
        node->left = left;
        node->right = right;
        ans.push_back(node);
      }
    }
  }
  return ans;
}

vector<TreeNode*> generateTrees(int n) {
  return __generateTrees(1, n);
}
