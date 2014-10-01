// Solution 1
vector<int> postorderTraversal(TreeNode *root) {
  vector<int> res;
  stack<TreeNode*> nodeStack;
  TreeNode *last = NULL;
  TreeNode *ptr = root;
  while ( ptr ) {
    nodeStack.push(ptr);
    ptr = ptr->left;
  }
  while ( !nodeStack.empty() ) {
    TreeNode *node = nodeStack.top();
    nodeStack.pop();
    if ( node->right == last || node->right == NULL ) {
      res.push_back(node->val);
      last = node;

    } else {
      nodeStack.push(node);
      node = node->right;
      while ( node ) {
        nodeStack.push(node);
        node = node->left;
      }
    }
  }
  return res;
}

// Solution 2
vector<int> postorderTraversal(TreeNode *root) {
  vector<int> res;
  TreeNode ROOT(0);
  ROOT.left = root;
  TreeNode *ptr = &ROOT;
  while ( ptr ) {
    if ( ptr->left ) {
      TreeNode *q = ptr->left;
      while ( q->right && q->right != ptr ) q = q->right;

      if ( q->right == NULL ) {
        q->right = ptr;
        ptr = ptr->left;

      } else {
        q->right = NULL;
        // reversely collect docs on the right linkedlist of ptr->left
        TreeNode *head = ptr->left;
        TreeNode *tail = head;
        while ( tail->right ) {
          TreeNode *node = tail->right;
          tail->right = node->right;
          node->right = head;
          head = node;
        }
        tail = head;
        res.push_back(tail->val);
        while ( tail->right ) {
          TreeNode *node = tail->right;
          res.push_back(node->val);
          tail->right = node->right;
          node->right = head;
          head = node;
        }
        ptr = ptr->right;
      }
    } else ptr = ptr->right;
  }
  return res;
}

