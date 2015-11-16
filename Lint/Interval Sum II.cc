// #redo
class Solution {
 public:
  struct SegmentTreeNode {
    long long sum = 0;
    int start, end;
    SegmentTreeNode *left = nullptr, *right = nullptr;
    SegmentTreeNode(int start, int end) : start(start), end(end) {}
    ~SegmentTreeNode() {
      if (left) delete left;
      if (right) delete right;
    }
  } *root = nullptr;

  Solution(vector<int> A) { root = __build(A, 0, (int)A.size() - 1); }

  ~Solution() {
    if (root) delete root;
  }

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

  long long query(int start, int end) { return __query(root, start, end); }

  void __modify(SegmentTreeNode *root, int index, int value) {
    if (root == nullptr) return;
    if (index < root->start || index > root->end) return;
    if (root->start == root->end) {
      root->sum = value;
      return;
    }
    __modify(root->left, index, value);
    __modify(root->right, index, value);
    root->sum = root->left->sum + root->right->sum;
  }

  void modify(int index, int value) { __modify(root, index, value); }
};
