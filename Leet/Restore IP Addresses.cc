// Redo
vector<string> restoreIpAddresses(string s) {
  vector<string> ans;
  const int N = s.size();
  for (int i = max(1,N-9); i <= 3 && i+3 <= N; ++ i) {
    if (i > 1 && s[0] == '0' || stoi(s.substr(0,i)) > 255) break;
    for (int j = max(i+1,N-6); j-i <= 3 && j+2 <= N; ++ j) {
      if (j-i > 1 && s[i] == '0' || stoi(s.substr(i,j-i)) > 255) break;
      for (int k = max(j+1,N-3); k-j <= 3 && k+1 <= N; ++ k) {
        if (k-j > 1 && s[j] == '0' || stoi(s.substr(j,k-j)) > 255) break;
        if (N-k > 1 && s[k] == '0' || stoi(s.substr(k)) > 255) continue;
        ans.push_back(s.substr(0,i) + "." + s.substr(i,j-i) + "." + s.substr(j,k-j) + "." + s.substr(k));
      }
    }
  }
  return ans;
}
