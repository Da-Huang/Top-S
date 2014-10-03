void flatten(TreeNode *root) {
  while ( root ) {
    if ( root->left ) {
      TreeNode *tail = root->left;
      while ( tail->right ) tail = tail->right;
      tail->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
    root = root->right;
  }
}

