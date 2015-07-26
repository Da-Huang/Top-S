void deleteNode(ListNode* node) {
  assert(node->next);
  ListNode *ptr = node->next;
  node->val = ptr->val;
  node->next = ptr->next;
  delete ptr;
}
