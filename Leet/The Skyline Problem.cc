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
  vector<pair<size_t, int>> hs;
  for (size_t i = 0; i < buildings.size(); ++ i) {
    hs.push_back(make_pair(i, 0));
    hs.push_back(make_pair(i, 1));
  }
  sort(hs.begin(), hs.end(), [&buildings](const pair<size_t, int> &p1, const pair<size_t, int> &p2) {
    return buildings[p1.first][p1.second] < buildings[p2.first][p2.second];
  });
  map<int, int> heightCounts;
  size_t begin = 0;
  int y = 0;
  while (begin < hs.size()) {
    size_t end = begin;
    int x = buildings[hs[begin].first][hs[begin].second];
    while (end < hs.size() && x == buildings[hs[end].first][hs[end].second]) {
      int h = buildings[hs[end].first][2];
      if (hs[end].second == 0) ++ heightCounts[h];
      else -- heightCounts[h];
      if (heightCounts[h] == 0) heightCounts.erase(h);
      ++ end;
    }
    int y2 = heightCounts.empty() ? 0 : (-- heightCounts.end())->first;
    if (y != y2) {
      y = y2;
      ans.push_back(make_pair(x, y));
    }
    begin = end;
  }
  return ans;
}
