class TrieNode {
public:
  TrieNode *dict[26];
  bool isWord = false;
  // Initialize your data structure here.
  TrieNode() {
    memset(dict, 0, sizeof(dict));
  }
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string s) {
    TrieNode *ptr = root;
    for (char c : s) {
      if (ptr->dict[c - 'a'] == NULL) ptr->dict[c - 'a'] = new TrieNode;
      ptr = ptr->dict[c - 'a'];
    }
    ptr->isWord = true;
  }

  // Returns if the word is in the trie.
  bool search(string key) {
    TrieNode *ptr = root;
    for (char c : key) {
      ptr = ptr->dict[c - 'a'];
      if (ptr == NULL) return false;
    }
    return ptr->isWord;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *ptr = root;
    for (char c : prefix) {
      ptr = ptr->dict[c - 'a'];
      if (ptr == NULL) return false;
    }
    return true;
  }

private:
  TrieNode* root;
};
