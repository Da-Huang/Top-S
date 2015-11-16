ListNode *partition(ListNode *head, int x) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode NEWHEAD(0);
  ListNode *tail = &NEWHEAD;
  ListNode *ptr = &HEAD;
  while ( ptr->next ) {
    if ( ptr->next->val < x ) {
      ListNode *node = ptr->next;
      ptr->next = node->next;
      tail->next = node;
      tail = node;

    } else {
      ptr = ptr->next;
    } 
  }
  tail->next = HEAD.next;
  return NEWHEAD.next;
}


// #redo
// #version2
ListNode* partition(ListNode* head, int x) {
  ListNode HEAD1(0), HEAD2(0);
  ListNode *tail1 = &HEAD1, *tail2 = &HEAD2;
  while (head) {
    if (head->val >= x) {
      tail2->next = head;
      tail2 = tail2->next;
    } else {
      tail1->next = head;
      tail1 = tail1->next;
    }
    head = head->next;
  }
  tail1->next = HEAD2.next;
  tail2->next = NULL;
  return HEAD1.next;
}
