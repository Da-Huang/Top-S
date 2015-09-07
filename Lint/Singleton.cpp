// #redo
class Solution {
 public:
  static Solution *getInstance() {
    if (instance == nullptr) instance = new Solution();
    return instance;
  }

 private:
  static Solution *instance;
};

Solution *Solution::instance = nullptr;
