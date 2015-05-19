// Redo
ListNode* mergeKLists(vector<ListNode*>& lists) {
  const int N = lists.size();
  int heap[N];
  int heapSize = 0;
  auto greaterList = [&lists] (int i, int j) {
    return lists[i]->val > lists[j]->val;
  };
  for (int i = 0; i < N; ++ i) {
    if (lists[i]) {
      heap[heapSize ++] = i;
      push_heap(heap, heap + heapSize, greaterList);
    }
  }

  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  while (heapSize) {
    int i = heap[0];
    tail->next = lists[i];
    tail = lists[i];
    lists[i] = lists[i]->next;

    pop_heap(heap, heap + heapSize --, greaterList);
    if (lists[i]) {
      heap[heapSize ++] = i;
      push_heap(heap, heap + heapSize, greaterList);
    }
  }
  return HEAD.next;
}
