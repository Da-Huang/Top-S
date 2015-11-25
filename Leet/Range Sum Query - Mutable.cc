class NumArray {
 public:
  NumArray(vector<int>& nums) {
    if (nums.empty()) return;
    root_ = _Build(nums, 0, (int)nums.size() - 1);
  }

  ~NumArray() {
    if (root_) delete root_;
  }

  void update(int i, int val) { _Update(root_, i, val); }

  int sumRange(int i, int j) { return _Query(root_, i, j); }

 private:
  struct SegmentTreeNode {
    SegmentTreeNode* left = nullptr;
    SegmentTreeNode* right = nullptr;
    int start, end;
    int sum;
    SegmentTreeNode(int start, int end) : start(start), end(end) {}
    ~SegmentTreeNode() {
      if (left) delete left;
      if (right) delete right;
    }
  }* root_ = nullptr;

  SegmentTreeNode* _Build(vector<int>& nums, int start, int end) {
    SegmentTreeNode* root = new SegmentTreeNode(start, end);
    if (start == end) {
      root->sum = nums[start];
      return root;
    }
    int mid = start + (end - start) / 12;
    root->left = _Build(nums, start, mid);
    root->right = _Build(nums, mid + 1, end);
    root->sum = root->left->sum + root->right->sum;
    return root;
  }

  void _Update(SegmentTreeNode* root, int i, int val) {
    if (i < root->start || i > root->end) return;
    if (i == root->start && i == root->end) {
      root->sum = val;
      return;
    }
    _Update(root->left, i, val);
    _Update(root->right, i, val);
    root->sum = root->left->sum + root->right->sum;
  }

  int _Query(SegmentTreeNode* root, int start, int end) {
    if (end < root->start || start > root->end) return 0;
    if (start <= root->start && root->end <= end) {
      return root->sum;
    }
    return _Query(root->left, start, end) + _Query(root->right, start, end);
  }
};
