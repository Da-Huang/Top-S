// #redo
ListNode* mergeKLists(vector<ListNode*>& lists) {
  const int N = lists.size();
  ListNode* heap[N];
  int heapSize = 0;
  auto greaterNode = [] (ListNode* p, ListNode* q) {
    return p->val > q->val;
  };
  for (int i = 0; i < N; ++ i) {
    if (lists[i]) {
      heap[heapSize ++] = lists[i];
      push_heap(heap, heap + heapSize, greaterNode);
    }
  }

  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  while (heapSize) {
    ListNode *node = heap[0];
    tail->next = node;
    tail = node;

    pop_heap(heap, heap + heapSize --, greaterNode);
    node = node->next;
    if (node) {
      heap[heapSize ++] = node;
      push_heap(heap, heap + heapSize, greaterNode);
    }
  }
  return HEAD.next;
}
