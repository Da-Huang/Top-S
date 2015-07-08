class Stack {
  queue<int> que;
 public:
  // Push element x onto stack.
  void push(int x) {
    que.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    queue<int> queBuffer;
    while (que.size() > 1) {
      queBuffer.push(que.front());
      que.pop();
    }
    que = move(queBuffer);
  }

  // Get the top element.
  int top() {
    queue<int> queBuffer;
    while (que.size() > 1) {
      queBuffer.push(que.front());
      que.pop();
    }
    int ans = que.front();
    queBuffer.push(que.front());
    que.pop();
    que = move(queBuffer);
    return ans;
  }

  // Return whether the stack is empty.
  bool empty() {
    return que.empty();
  }
};
