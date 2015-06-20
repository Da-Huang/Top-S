RandomListNode *copyRandomList(RandomListNode *head) {
  unordered_map<RandomListNode*, RandomListNode*> MAP;
  RandomListNode HEAD(0);
  RandomListNode *tail = &HEAD;
  for (RandomListNode *ptr = head; ptr; ptr = ptr->next) {
    tail->next = MAP[ptr] = new RandomListNode(ptr->label);
    tail = tail->next;
  }
  for (RandomListNode *ptr = head; ptr; ptr = ptr->next) {
    if (ptr->random) {
      MAP[ptr]->random = MAP[ptr->random];
    }
  }
  return HEAD.next;
}
