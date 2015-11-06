RandomListNode* copyRandomList(RandomListNode* head) {
  unordered_map<RandomListNode*, RandomListNode*> MAP;
  RandomListNode HEAD(0);
  RandomListNode* tail = &HEAD;
  for (RandomListNode* ptr = head; ptr; ptr = ptr->next) {
    tail->next = MAP[ptr] = new RandomListNode(ptr->label);
    tail = tail->next;
  }
  for (RandomListNode* ptr = head; ptr; ptr = ptr->next) {
    if (ptr->random) {
      MAP[ptr]->random = MAP[ptr->random];
    }
  }
  return HEAD.next;
}

// #version2
RandomListNode* copyRandomList(RandomListNode* head) {
  for (RandomListNode* ptr = head; ptr; ptr = ptr->next) {
    RandomListNode* node = new RandomListNode(ptr->label);
    node->next = ptr->next;
    ptr->next = node;
    ptr = node;
  }
  for (RandomListNode* ptr = head; ptr; ptr = ptr->next) {
    RandomListNode* node = ptr->next;
    node->random = ptr->random ? ptr->random->next : nullptr;
    ptr = node;
  }
  RandomListNode HEAD(0);
  RandomListNode* tail = &HEAD;
  for (RandomListNode* ptr = head; ptr; ptr = ptr->next) {
    RandomListNode* node = ptr->next;
    ptr->next = node->next;
    tail->next = node;
    tail = node;
  }
  return HEAD.next;
}
