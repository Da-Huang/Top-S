RandomListNode *copyRandomList(RandomListNode *head) {
  unordered_map<RandomListNode*, RandomListNode*> mapping;
  RandomListNode HEAD(0);
  RandomListNode *tail = &HEAD;
  for (RandomListNode *ptr = head; ptr; ptr = ptr->next) {
    tail->next = mapping[ptr] = new RandomListNode(ptr->label);
    tail = tail->next;
  }
  for (RandomListNode *ptr = head, *q = HEAD.next; ptr; ptr = ptr->next, q = q->next) {
    if ( ptr->random ) {
      q->random = mapping[ptr->random];
    }
  }
  return HEAD.next;
}
