// #redo
int __digestNum(const string &input, size_t *i) {
    size_t j = *i + 1;
    while (j < input.size() && isdigit(input[j])) ++j;
    int ans = stoi(input.substr(*i, j - *i));
    *i = j;
    return ans;
}

vector<int> __diffWaysToCompute(vector<int> &nums, vector<char> &ops, int first, int last) {
    vector<int> ans;
    if (first == last) {
        ans.push_back(nums[first]);
        return ans;
    }
    for (int i = first; i < last; ++i) {
        vector<int> ans1 = __diffWaysToCompute(nums, ops, first, i);
        vector<int> ans2 = __diffWaysToCompute(nums, ops, i+1, last);
        for (int num1 : ans1) {
            for (int num2 : ans2) {
                switch (ops[i]) {
                    case '+': ans.push_back(num1 + num2); break;
                    case '-': ans.push_back(num1 - num2); break;
                    case '*': ans.push_back(num1 * num2); break;
                    case '/': ans.push_back(num1 / num2); break;
                }
            }
        }
    }
    return ans;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> nums;
    vector<char> ops;
    size_t i = 0;
    nums.push_back(__digestNum(input, &i));
    while (i < input.size()) {
        ops.push_back(input[i++]);
        nums.push_back(__digestNum(input, &i));        
    }
    if (nums.empty()) return {};
    return __diffWaysToCompute(nums, ops, 0, (int)nums.size() - 1);
}
