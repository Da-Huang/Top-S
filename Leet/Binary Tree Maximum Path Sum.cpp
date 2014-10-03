// Redo
pair<int, int> __maxPathSum(TreeNode *root) {
  if ( root->left == NULL && root->right == NULL )
    return make_pair(root->val, root->val);
  int l1 = INT_MIN, l2 = INT_MIN;
  int r1 = INT_MIN, r2 = INT_MIN;
  if ( root->left ) {
    auto l = __maxPathSum(root->left);
    l1 = l.first;
    l2 = l.second;
  }
  if ( root->right ) {
    auto r = __maxPathSum(root->right);
    r1 = r.first;
    r2 = r.second;
  }
  int res1 = max({l1, r1, 0}) + root->val;
  int res2 = max({res1, l1, r1, l2, r2, max(l1, 0) + max(r1, 0) + root->val});
  return make_pair(res1, res2);
}

int maxPathSum(TreeNode *root) {
  if ( root == NULL ) return 0;
  return __maxPathSum(root).second;
}

