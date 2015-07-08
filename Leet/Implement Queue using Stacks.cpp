class Queue {
  stack<int> pushStack;
  stack<int> popStack;
 public:
  // Push element x to the back of queue.
  void push(int x) {
    pushStack.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if (popStack.empty()) {
      while (!pushStack.empty()) {
        popStack.push(pushStack.top());
        pushStack.pop();
      }
    }
    popStack.pop();
  }

  // Get the front element.
  int peek(void) {
    if (popStack.empty()) {
      while (!pushStack.empty()) {
        popStack.push(pushStack.top());
        pushStack.pop();
      }
    }
    return popStack.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return pushStack.empty() && popStack.empty();
  }
};
