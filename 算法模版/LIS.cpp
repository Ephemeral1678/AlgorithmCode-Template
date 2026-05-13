#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;  // tails[i]：长度为i+1的LIS的最小末尾值
    for (int num : nums) {
        // 二分找第一个>=num的位置(如果是最长不下降子序列则改为upper_bound)
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);  // 扩展LIS
        } else {
            *it = num;  // 替换为更小的末尾值，优化后续选择
        }
    }
    return tails.size();
}

// 示例使用
int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;  // 输出4（2,3,7,101）
    return 0;
}