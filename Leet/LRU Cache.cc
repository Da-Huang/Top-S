class LRUCache{
  unordered_map<int, list<pair<int, int>>::iterator> cache;
  list<pair<int, int>> que;
  int size = 0;
  const int capacity;
public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) return -1;
    que.push_back(*(it->second));
    que.erase(it->second);
    it->second = -- que.end();
    return it->second->second;
  }

  void set(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) que.erase(it->second);
    else ++ size;

    que.push_back(make_pair(key, value));
    cache[key] = -- que.end();

    if (size > capacity) {
      cache.erase(que.front().first);
      que.pop_front();
      -- size;
    }
  }
};
