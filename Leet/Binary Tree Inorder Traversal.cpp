vector<int> inorderTraversal(TreeNode *root) {
  vector<int> res;
  TreeNode *ptr = root;
  while ( ptr ) {
    if ( ptr->left ) {
      TreeNode *q = ptr->left;
      while ( q->right && q->right != ptr ) q = q->right;
      if ( q->right == NULL ) {
        q->right = ptr;
        ptr = ptr->left;

      } else {
        q->right = NULL;
        res.push_back(ptr->val);
        ptr = ptr->right;
      }

    } else {
      res.push_back(ptr->val);
      ptr = ptr->right;
    }
  }
  return res;
}

