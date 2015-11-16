class BSTIterator {
  stack<TreeNode*> stk;
  TreeNode *last;
  public:
  BSTIterator(TreeNode *root) : last(root) {}

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return last || !stk.empty();
  }

  /** @return the next smallest number */
  int next() {
    while (last) {
      stk.push(last);
      last = last->left;
    }
    TreeNode *node = stk.top();
    stk.pop();
    last = node->right;
    return node->val;
  }
};
