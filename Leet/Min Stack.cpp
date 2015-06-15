// #redo
class MinStack {
  stack<int> stk;
  stack<int> minStack;
public:
  void push(int x) {
    if (minStack.empty() || minStack.top() >= x) minStack.push(x);
    stk.push(x);
  }

  void pop() {
    if (stk.top() == minStack.top()) minStack.pop();
    stk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return minStack.top();
  }
};
