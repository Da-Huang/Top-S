class Solution {
 public:
  /**
   * This method will be invoked first, you should design your own algorithm
   * to serialize a binary tree which denote by a root node to a string which
   * can be easily deserialized by your own "deserialize" method later.
   */
  string serialize(TreeNode *root) {
    if (root == nullptr) return "";
    string ans;
    queue<TreeNode *> que;
    que.push(root);
    ans += to_string(root->val) + " ";
    while (!que.empty()) {
      TreeNode *node = que.front();
      que.pop();
      if (node->left) {
        ans += to_string(node->left->val) + " ";
        que.push(node->left);
      } else {
        ans += "# ";
      }
      if (node->right) {
        ans += to_string(node->right->val) + " ";
        que.push(node->right);
      } else {
        ans += "# ";
      }
    }
    return ans;
  }

  /**
   * This method will be invoked second, the argument data is what exactly
   * you serialized at method "serialize", that means the data is not given by
   * system, it's given by your own serialize method. So the format of data is
   * designed by yourself, and deserialize it here as you serialize it in
   * "serialize" method.
   */
  TreeNode *deserialize(string data) {
    TreeNode *root = nullptr;
    queue<TreeNode **> que;
    que.push(&root);
    size_t i = 0;
    while (i < data.size()) {
      size_t j = i + 1;
      while (j < data.size() && data[j] != ' ') ++j;
      TreeNode *&node = *que.front();
      que.pop();
      if (data[i] == '#')
        node = nullptr;
      else {
        node = new TreeNode(stoi(data.substr(i, j - i)));
        que.push(&node->left);
        que.push(&node->right);
      }
      i = j + 1;
    }
    return root;
  }
};
