// #redo
struct TrieNode {
  TrieNode *dict[26];
  bool isEnd = false;
  TrieNode() {
    memset(dict, 0, sizeof(dict));
  }
};

class WordDictionary {
  TrieNode *root = new TrieNode();
  public:
  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode *ptr = root;
    for (char c : word) {
      if (ptr->dict[c-'a'] == NULL) ptr->dict[c-'a'] = new TrieNode();
      ptr = ptr->dict[c-'a'];
    }
    ptr->isEnd = true;
  }

  bool __search(string &word, size_t begin, TrieNode *ptr) {
    if (ptr == NULL) return false;
    if (begin == word.size()) return ptr->isEnd;
    if (word[begin] != '.') return __search(word, begin+1, ptr->dict[word[begin]-'a']);
    for (TrieNode *q : ptr->dict) {
      if (__search(word, begin+1, q)) return true;
    }
    return false;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return __search(word, 0, root);
  }
};
