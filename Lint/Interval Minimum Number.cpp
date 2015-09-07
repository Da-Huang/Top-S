// #redo
struct SegmentTreeNode {
  SegmentTreeNode *left = nullptr, *right = nullptr;
  int start, end;
  int min_value;
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
    root->min_value = A[start];
    return root;
  }
  int mid = start + (end - start) / 2;
  root->left = __build(A, start, mid);
  root->right = __build(A, mid + 1, end);
  root->min_value = min(root->left->min_value, root->right->min_value);
  return root;
}

int __query(SegmentTreeNode *root, int start, int end) {
  if (root == nullptr || end < root->start || root->end < start) return INT_MAX;
  if (start <= root->start && root->end <= end) return root->min_value;
  return min(__query(root->left, start, end), __query(root->right, start, end));
}

vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
  SegmentTreeNode *root = __build(A, 0, (int)A.size() - 1);
  vector<int> ans;
  for (const Interval &query : queries) {
    ans.push_back(__query(root, query.start, query.end));
  }
  delete root;
  return ans;
}
