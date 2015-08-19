void __binaryTreePaths(TreeNode *root, vector<TreeNode*> &path, vector<string> &ans) {
  if (root->left == nullptr && root->right == nullptr) {
    ans.push_back("");
    for (TreeNode *node : path) {
      ans.back() += to_string(node->val) + "->";
    }
    ans.back() += to_string(root->val);
    return;
  }
  path.push_back(root);
  if (root->left) __binaryTreePaths(root->left, path, ans);
  if (root->right) __binaryTreePaths(root->right, path, ans);
  path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
  if (root == nullptr) return {};
  vector<string> ans;
  vector<TreeNode*> path;
  __binaryTreePaths(root, path, ans);
  return ans;
}
