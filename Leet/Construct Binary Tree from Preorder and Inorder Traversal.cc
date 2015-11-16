TreeNode *__buildTree(vector<int>& preorder, vector<int>& inorder, int preBegin, int inBegin, int N) {
  if (N == 0) return NULL;
  TreeNode *root = new TreeNode(preorder[preBegin]);
  int k;
  for (k = 0; k < N; ++ k) {
    if (inorder[inBegin+k] == root->val) break;
  }
  root->left = __buildTree(preorder, inorder, preBegin + 1, inBegin, k);
  root->right = __buildTree(preorder, inorder, preBegin + 1 + k, inBegin + k + 1, N - k - 1);
  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  return __buildTree(preorder, inorder, 0, 0, (int) preorder.size());
}


// #version2
TreeNode *__buildTree(vector<int>& preorder, vector<int>& inorder, int preBegin, int inBegin, int N, unordered_map<int, int> &inMap) {
  if (N == 0) return NULL;
  TreeNode *root = new TreeNode(preorder[preBegin]);
  int k = inMap[root->val] - inBegin;
  root->left = __buildTree(preorder, inorder, preBegin + 1, inBegin, k, inMap);
  root->right = __buildTree(preorder, inorder, preBegin + 1 + k, inBegin + k + 1, N - k - 1, inMap);
  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, int> inMap;
  for (int i = 0; i < (int) inorder.size(); ++ i) inMap[inorder[i]] = i;
  return __buildTree(preorder, inorder, 0, 0, (int) preorder.size(), inMap);
}
