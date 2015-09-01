struct SegmentTreeNode {
  long long sum = 0;
  int start, end;
  SegmentTreeNode *left = nullptr, *right = nullptr;
  SegmentTreeNode(int start, int end) : start(start), end(end) {}
  ~SegmentTreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

SegmentTreeNode *__build(const vector<int> &A, int start, int end) {
  if (start > end) return nullptr;
  SegmentTreeNode *root = new SegmentTreeNode(start, end);
  if (start == end) {
    root->sum = A[start];
    return root;
  }
  int mid = start + (end - start) / 2;
  root->left = __build(A, start, mid);
  root->right = __build(A, mid + 1, end);
  root->sum = root->left->sum + root->right->sum;
  return root;
}

long long __query(SegmentTreeNode *root, int start, int end) {
  if (root == nullptr) return 0;
  if (end < root->start || start > root->end) return 0;
  if (start <= root->start && root->end <= end) return root->sum;
  return __query(root->left, start, end) + __query(root->right, start, end);
}

vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
  SegmentTreeNode *root = __build(A, 0, (int)A.size() - 1);
  vector<long long> ans;
  for (const auto &query : queries) {
    ans.push_back(__query(root, query.start, query.end));
  }
  if (root) delete root;
  return ans;
}
