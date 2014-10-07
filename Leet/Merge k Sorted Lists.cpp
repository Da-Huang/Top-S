// Redo
ListNode *mergeKLists(vector<ListNode *> &lists) {
  const int N = lists.size();
  int pq[N];
  int pqLen = 0;
  auto lessNode = [&lists] (int i, int j) {
    return lists[i]->val > lists[j]->val;
  };
  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  for (int i = 0; i < N; i ++) {
    if ( lists[i] ) {
      pq[pqLen ++] = i;
      push_heap(pq, pq + pqLen, lessNode);
    }
  }
  while ( pqLen ) {
    pop_heap(pq, pq + pqLen, lessNode);
    int i = pq[-- pqLen];
    ListNode *node = lists[i];
    lists[i] = lists[i]->next;
    if ( lists[i] ) {
      pq[pqLen ++] = i;
      push_heap(pq, pq + pqLen, lessNode);
    }
    tail->next = node;
    tail = node;
  }
  return HEAD.next;
}

