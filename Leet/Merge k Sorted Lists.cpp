// Redo
ListNode *mergeKLists(vector<ListNode *> &lists) {
  ListNode HEAD(0);
  ListNode *tail = &HEAD;
  const int N = lists.size();
  ListNode *begin[N];
  for (int i = 0; i < N; i ++) begin[i] = lists[i];

  auto lessNode = [&begin] (int i, int j) { // should be greater
    return begin[i]->val > begin[j]->val;
  };
  int pq[N];
  int pqLen = 0;
  for (int i = 0; i < N; i ++) {
    if ( begin[i] ) {
      pq[pqLen ++] = i;
      push_heap(pq, pq + pqLen, lessNode);
    }
  }
  while ( pqLen ) {
    pop_heap(pq, pq + pqLen, lessNode);
    pqLen --;
    ListNode *node = begin[pq[pqLen]];
    begin[pq[pqLen]] = node->next;
    tail->next = node;
    node->next = NULL;
    tail = node;

    if ( begin[pq[pqLen]] ) {
      pqLen ++;
      push_heap(pq, pq + pqLen, lessNode);
    }
  }
  return HEAD.next;
}

