pair<int, bool> isBalancedInner(TreeNode *root) {
  if ( root == NULL ) return make_pair(0, true);
  auto l = isBalancedInner(root->left);
  if ( !l.second ) return make_pair(-1, false);
  auto r = isBalancedInner(root->right);
  if ( !r.second ) return make_pair(-1, false);
  if ( abs(l.first - r.first) <= 1 )
    return make_pair(max(l.first, r.first) + 1, true);
  else return make_pair(-1, false);
}

bool isBalanced(TreeNode *root) {
  return isBalancedInner(root).second;
}

