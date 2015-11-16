// #redo
int kthSmallest(TreeNode* root, int k) {
    int ans;
    while (root) {
        TreeNode *lr = root->left;
        if (lr) {
            while (lr->right && lr->right != root) lr = lr->right;
            if (lr->right) {
                lr->right = NULL;

            } else {
                lr->right = root;
                root = root->left;
                continue;
            }
        }
        if (--k == 0) ans = root->val;
        root = root->right;
    }
    return ans;
}


// #version2
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    TreeNode *rl = root;
    while (rl || !stk.empty()) {
        while (rl) {
            stk.push(rl);
            rl = rl->left;
        }
        TreeNode *node = stk.top();
        stk.pop();
        if (--k == 0) return node->val;
        rl = node->right;
    }
    return -1;
}
