vector<vector<int> > pathSum(TreeNode *root, int sum) {
  vector<vector<int>> res;
  if ( root == NULL ) return res;
  if ( root->left == NULL && root->right == NULL ) {
    if ( root->val == sum ) {
      res.push_back(vector<int>(1, root->val));
    }
    return res;
  }
  if ( root->left ) {
    vector<vector<int>> subRes = pathSum(root->left, sum - root->val);
    for (auto &item : subRes) {
      item.insert(item.begin(), root->val);
      res.push_back(item);
    }
  }
  if ( root->right ) {
    vector<vector<int>> subRes = pathSum(root->right, sum - root->val);
    for (auto &item : subRes) {
      item.insert(item.begin(), root->val);
      res.push_back(item);
    }
  }
  return res;
}

