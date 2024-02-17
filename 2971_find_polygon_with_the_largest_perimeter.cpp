class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      const long long total = accumulate(nums.begin()
                                         , nums.end()
                                         , static_cast<long long>(0));

      sort(nums.begin(), nums.end());

      const int L = nums.size();
      long long bRunningSum = 0;
      for (int i = L - 1; i >= 2; --i) {
        bRunningSum += nums[i];
        if (total - bRunningSum > nums[i]) {
          return total - bRunningSum + nums[i];
        }
      }

      return -1;
    }
};

// topic: greedy
// time complexity: O(nlogn), space complexity: O(1)
