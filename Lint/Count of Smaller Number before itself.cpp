struct SegmentTreeNode {
  SegmentTreeNode *left = nullptr, *right = nullptr;
  int start, end;
  int count = 0;
  SegmentTreeNode(int start, int end) : start(start), end(end) {}

  ~SegmentTreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

void insert(SegmentTreeNode *root, int val) {
  if (val < root->start || val > root->end) return;
  while (root->start < root->end) {
    ++root->count;
    int mid = root->start + (root->end - root->start) / 2;
    if (val <= mid) {
      if (root->left == nullptr)
        root->left = new SegmentTreeNode(root->start, mid);
      root = root->left;
    } else {
      if (root->right == nullptr)
        root->right = new SegmentTreeNode(mid + 1, root->end);
      root = root->right;
    }
  }
  ++root->count;
}

int query(SegmentTreeNode *root, int end) {
  int ans = 0;
  while (root) {
    if (end >= root->end) return ans + root->count;
    if (end < root->start) return ans;
    int mid = root->start + (root->end - root->start) / 2;
    if (end >= mid) {
      if (root->left) ans += root->left->count;
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return ans;
}

vector<int> countOfSmallerNumberII(vector<int> &A) {
  if (A.empty()) return {};
  int min_value = *min_element(A.begin(), A.end());
  int max_value = *max_element(A.begin(), A.end());
  SegmentTreeNode ROOT(min_value, max_value);
  vector<int> ans;
  for (int num : A) {
    ans.push_back(query(&ROOT, num - 1));
    insert(&ROOT, num);
  }
  return ans;
}
