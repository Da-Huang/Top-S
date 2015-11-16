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


// #redo
// #version2
void __pathSum(TreeNode* root, int sum, vector<int> &v, vector<vector<int>> &ans) {
  if (root->left == NULL && root->right == NULL) {
    if (sum == root->val) {
      ans.push_back(v);
      ans.back().push_back(root->val);
    }
    return;
  }
  v.push_back(root->val);
  if (root->left) __pathSum(root->left, sum - root->val, v, ans);
  if (root->right) __pathSum(root->right, sum - root->val, v, ans);
  v.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
  vector<vector<int>> ans;
  if (root == NULL) return ans;
  vector<int> v;
  __pathSum(root, sum, v, ans);
  return ans;
}
