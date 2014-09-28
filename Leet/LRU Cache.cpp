class LRUCache{
private:
  unordered_map<int, list<pair<int, int>>::iterator> cache;
  list<pair<int, int>> pairs;
  const int capacity;
public:
  LRUCache(int capacity) : capacity(capacity) {
  }

  int get(int key) {
    auto it = cache.find(key);
    if ( it == cache.end() ) return -1;
    auto entry = *(it->second);
    pairs.erase(it->second);
    pairs.push_back(entry);
    auto jt = pairs.end();
    it->second = -- jt;
    return jt->second;
  }

  void set(int key, int value) {
    auto it = cache.find(key);
    if ( it == cache.end() ) {
      pairs.push_back(make_pair(key, value));
      if ( pairs.size() > capacity ) {
        cache.erase(pairs.front().first);
        pairs.pop_front();
      }
    } else {
      pairs.erase(it->second);
      pairs.push_back(make_pair(key, value));
    }
    auto jt = pairs.end();
    cache[key] = -- jt;
  }
};
