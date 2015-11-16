int minDepth(TreeNode* root) {
  if (root == NULL) return 0;
  if (root->left == NULL && root->right == NULL) return 1;
  if (root->left && root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
  if (root->left) return minDepth(root->left) + 1;
  /* root->right */ return minDepth(root->right) + 1;
}
