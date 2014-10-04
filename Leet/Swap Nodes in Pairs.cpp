ListNode *swapPairs(ListNode *head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode *ptr = &HEAD;
  while ( ptr->next && ptr->next->next ) {
    ListNode *node1 = ptr->next;
    ListNode *node2 = node1->next;
    ptr->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    ptr = node1;
  }
  return HEAD.next;
}

