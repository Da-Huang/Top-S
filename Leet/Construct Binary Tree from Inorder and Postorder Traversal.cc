// #redo
TreeNode* __buildTree(vector<int>& inorder, vector<int>& postorder,
    int inBegin, int postBegin, int n, unordered_map<int, int> &mapping) {
  if (n == 0) return NULL;
  TreeNode *root = new TreeNode(postorder[postBegin + n - 1]);
  int k = mapping[root->val];
  root->left = __buildTree(inorder, postorder, inBegin, postBegin, k - inBegin, mapping);
  root->right = __buildTree(inorder, postorder, k + 1, postBegin + k - inBegin, n - 1 - k + inBegin, mapping);
  return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  if (inorder.size() != postorder.size()) return NULL;
  unordered_map<int, int> mapping;
  const int N = inorder.size();
  for (int i = 0; i < N; ++ i) mapping[inorder[i]] = i;
  return __buildTree(inorder, postorder, 0, 0, N, mapping);
}
