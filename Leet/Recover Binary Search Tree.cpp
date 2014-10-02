void recoverTree(TreeNode *root) {
  TreeNode *p1 = NULL, *p2 = NULL;
  TreeNode *last = NULL;
  TreeNode *ptr = root;
  while ( ptr ) {
    if ( ptr->left ) {
      TreeNode *q = ptr->left;
      while ( q->right && q->right != ptr ) q = q->right;
      if ( q->right == NULL ) {
        q->right = ptr;
        ptr = ptr->left;
        continue;
      }
      // q->right == ptr
      q->right = NULL;
    }
    // deal with ptr;
    if ( last && last->val > ptr->val ) {
      if ( p1 ) p2 = ptr;
      else {
        p1 = last;
        p2 = ptr;
      }
    }
    last = ptr;
    ptr = ptr->right;
  }
  swap(p1->val, p2->val);
}
