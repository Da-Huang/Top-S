vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> res;
  if ( root == NULL ) return res;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  bool isRight = true;
  vector<int> subRes;
  while ( !q.empty() ) {
    TreeNode *node = q.front();
    q.pop();
    if ( node == NULL ) {
      if ( !isRight ) {
        reverse(subRes.begin(), subRes.end());
      }
      res.push_back(subRes);
      subRes.clear();
      isRight = !isRight;
      if ( q.empty() ) break;
      q.push(NULL);
      continue;
    }
    subRes.push_back(node->val);
    if ( node->left ) q.push(node->left);
    if ( node->right ) q.push(node->right);
  }
  return res;
}

