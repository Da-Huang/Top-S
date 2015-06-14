// #redo
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  vector<pair<int, int>> ans;
  stack<pair<int, int>> stk;
  int lastHeight = 0;
  for (auto &building : buildings) {
    while (!stk.empty() && stk.top().first < building[0]) {
      ans.push_back(stk.top());
      lastHeight = stk.top().second;
      stk.pop();
    }
    stack<pair<int, int>> buffer;
    if (lastHeight < building[2]) {
      ans.push_back(make_pair(building[0], building[2]));
      int height = lastHeight;
      while (!stk.empty() && stk.top().first <= building[1]) {
        height = stk.top().second;
        stk.pop();
      }
      stk.push(make_pair(building[1], height));
      lastHeight = building[2];

    } else { // lastHeight >= building[2]
      int height = lastHeight;
      while (!stk.empty() && stk.top().second >= building[2] && stk.top().first < building[1]) {
        height = stk.top().second;
        buffer.push(stk.top());
        stk.pop();
      }
      if (!stk.empty() && stk.top().first >= building[1]) {
        while (!buffer.empty()) {
          stk.push(buffer.top());
          buffer.pop();
        }
      } else {
        if (building[2] < lastHeight) buffer.push(make_pair(stk.top().first, building[2]));
        height = building[2];
        while (!stk.empty() && stk.top().first <= building[1]) {
          height = stk.top().second;
          stk.pop();
        }
        stk.push(make_pair(building[1], height));
        while (!buffer.empty()) {
          stk.push(buffer.top());
          buffer.pop();
        }
      }
    }
  }
  while (!stk.empty()) {
    ans.push_back(stk.top());
    stk.pop();
  }
  return ans;
}


// #version2
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  vector<pair<int, int>> ans;
  vector<pair<size_t, int>> v;
  for (size_t i = 0; i < buildings.size(); ++ i) {
    v.push_back(make_pair(i, 0));
    v.push_back(make_pair(i, 1));
  }
  sort(v.begin(), v.end(), [&buildings] (const pair<size_t, int> &p1, const pair<size_t, int> &p2) {
    if (buildings[p1.first][p1.second] < buildings[p2.first][p2.second]) return true;
    if (buildings[p1.first][p1.second] > buildings[p2.first][p2.second]) return false;
    return p1.second < p2.second;
  });

  multiset<int> heights;
  size_t begin = 0;
  int lastHeight = 0;
  while (begin < v.size()) {
    size_t end = begin;
    int x = buildings[v[begin].first][v[begin].second];
    while (end < v.size() && buildings[v[end].first][v[end].second] == x) {
      int height = buildings[v[end].first][2];
      if (v[end].second == 0) heights.insert(height);
      else heights.erase(heights.find(height));
      ++ end;
    }
    int height = heights.empty() ? 0 : *(-- heights.end());
    if (lastHeight != height) ans.push_back(make_pair(x, height));
    lastHeight = height;
    begin = end;
  }
  return ans;
}


// #solution3 #divide-and-conquer
