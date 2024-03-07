class Solution {
public:
    int missingNumber(vector<int>& nums) {
      const int N = nums.size();
      long sum = accumulate(nums.begin(), nums.end(), 0LL);
      long trueSum = N * (N + 1) / 2;
      return trueSum - sum;
    }
};

// topics: array, math, bit manipulation
// time complexity: O(n), space complexity: O(1)
