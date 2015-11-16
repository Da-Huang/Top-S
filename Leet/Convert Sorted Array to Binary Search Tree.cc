TreeNode *__sortedArrayToBST(vector<int>& nums, int first, int last) {
  if (first > last) return NULL;
  int mid = first + (last - first) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = __sortedArrayToBST(nums, first, mid - 1);
  root->right = __sortedArrayToBST(nums, mid + 1, last);
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  return __sortedArrayToBST(nums, 0, ((int) nums.size()) - 1);
}
