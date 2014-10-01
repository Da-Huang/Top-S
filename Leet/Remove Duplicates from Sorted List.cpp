ListNode *deleteDuplicates(ListNode *head) {
  if ( head == NULL ) return NULL;
  ListNode *begin = head;
  while ( begin->next ) {
    ListNode *node = begin->next;
    if ( node->val == begin->val ) {
      begin->next = node->next;
      delete node;

    } else {
      begin = node;
    }
  }
  return head;
}

