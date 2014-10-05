TreeNode *copy(TreeNode *root) {
  if ( root == NULL ) return NULL;
  TreeNode *newRoot = new TreeNode(root->val);
  newRoot->left = copy(root->left);
  newRoot->right = copy(root->right);
  return newRoot;
}

void del(TreeNode *root) {
  if ( root == NULL ) return;
  del(root->left);
  del(root->right);
  delete root;
}

vector<TreeNode *> __gen(int first, int last) {
  vector<TreeNode*> res;
  if ( first > last ) {
    res.push_back(NULL);
    return res;
  }

  for (int i = first; i <= last; i ++) {
    vector<TreeNode*> l = __gen(first, i - 1);
    vector<TreeNode*> r = __gen(i + 1, last);
    for (auto &lu : l) {
      for (auto &ru : r) {
        TreeNode *root = new TreeNode(i);
        root->left = copy(lu);
        root->right = copy(ru);
        res.push_back(root);
      }
    }
    for (auto &lu : l) del(lu);
    for (auto &ru : r) del(ru);
  }
  return res;
}

vector<TreeNode *> generateTrees(int n) {
  return __gen(1, n);
}

