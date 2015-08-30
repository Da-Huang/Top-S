// #redo
vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
  vector<pair<int, int>> vlines;
  for (int i = 0; i < (int)buildings.size(); ++i) {
    vlines.push_back(make_pair(i, 0));
    vlines.push_back(make_pair(i, 1));
  }
  sort(vlines.begin(), vlines.end(),
       [&buildings](const pair<int, int> &p1, const pair<int, int> &p2) {
         int i1 = buildings[p1.first][p1.second];
         int i2 = buildings[p2.first][p2.second];
         if (i1 < i2) return true;
         if (i1 > i2) return false;
         return p1.second < p2.second;
       });

  vector<vector<int>> ans;
  multiset<int> height_set;
  int first = 0, height = 0;
  for (const auto &vline : vlines) {
    int new_height = buildings[vline.first][2];
    if (height_set.empty()) {
      height_set.insert(height = new_height);
      first = buildings[vline.first][vline.second];
    } else {
      if (vline.second == 0) {
        height_set.insert(new_height);
      } else {
        height_set.erase(height_set.find(new_height));
      }
      new_height = height_set.empty() ? 0 : *prev(height_set.end());
      if (height != new_height) {
        int last = buildings[vline.first][vline.second];
        if (first < last) ans.push_back({first, last, height});
        height = new_height;
        first = last;
      }
    }
  }
  return ans;
}
