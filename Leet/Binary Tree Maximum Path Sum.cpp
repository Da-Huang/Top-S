// #redo
pair<int, int> __maxPathSum(TreeNode *root) {
  if (root->left == NULL && root->right == NULL) return make_pair(root->val, root->val);
  pair<int, int> leftAns, rightAns;
  int leftSingle, rightSingle;
  if (root->left) {
    leftAns = __maxPathSum(root->left);
    leftSingle = root->val + max(leftAns.second, 0);
    if (root->right == NULL) return make_pair(max(leftSingle, leftAns.first), leftSingle);
  }
  if (root->right) {
    rightAns = __maxPathSum(root->right);
    rightSingle = root->val + max(rightAns.second, 0);
    if (root->left == NULL) return make_pair(max(rightSingle, rightAns.first), rightSingle);
  }
  return make_pair(max({leftAns.first, rightAns.first, leftSingle + rightSingle - root->val}), max(leftSingle, rightSingle));
}

int maxPathSum(TreeNode* root) {
  return __maxPathSum(root).first;
}
