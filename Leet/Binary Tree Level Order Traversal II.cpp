vector<vector<int> > levelOrderBottom(TreeNode *root) {
  vector<vector<int>> res;
  if ( root == NULL ) return res;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  vector<int> line;
  while ( !q.empty() ) {
    TreeNode *node = q.front();
    q.pop();
    if ( node == NULL ) {
      res.insert(res.begin(), line);
      line.clear();
      if ( q.empty() ) break;
      q.push(NULL);

    } else {
      line.push_back(node->val);
      if ( node->left ) q.push(node->left);
      if ( node->right ) q.push(node->right);
    }
  }
  return res;
}

