ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == NULL) return NULL;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *p = &HEAD;
  for (int i = 0; i < n; ++ i) {
    if (p->next == NULL) return head;
    p = p->next;
  }
  ListNode *q = &HEAD;
  while (p->next) {
    p = p->next;
    q = q->next;
  }
  ListNode *node = q->next;
  q->next = node->next;
  delete node;
  return HEAD.next;
}


// #version2
ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == NULL) return NULL;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *cache[n];
  int count = 0;
  for (ListNode *ptr = &HEAD; ptr->next; ptr = ptr->next) cache[(count ++)%n] = ptr;
  ListNode *ptr = cache[(count - n)%n];
  ListNode *node = ptr->next;
  ptr->next = node->next;
  delete node;
  return HEAD.next;
}
