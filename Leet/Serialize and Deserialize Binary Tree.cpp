// #redo
// dfs
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string ans;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* node = stk.top();
      stk.pop();
      if (node) {
        ans += to_string(node->val);
        stk.push(node->right);
        stk.push(node->left);
      }
      ans += ",";
    }
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    TreeNode* root = nullptr;
    stack<TreeNode*> stk;
    bool handling_left = true;
    int i = 0;
    while (i < (int)data.size()) {
      int j = i;
      while (j < (int)data.size() && data[j] != ',') ++j;
      if (j == i) {
        if (handling_left) {
          handling_left = false;
        } else {
          TreeNode* node = stk.top();
          stk.pop();
        }
      } else {
        int val = stoi(data.substr(i, j - i));
        TreeNode* node = new TreeNode(val);
        if (handling_left) {
          if (stk.empty()) {
            root = node;
          } else {
            stk.top()->left = node;
          }
        } else {
          stk.top()->right = node;
          stk.pop();
        }
        stk.push(node);
        handling_left = true;
      }
      i = j + 1;
    }
    return root;
  }
};
