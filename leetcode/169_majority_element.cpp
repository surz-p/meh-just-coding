class Solution {
public:
    int majorityElement(vector<int>& nums) {
      const int L = nums.size();
      int maxCount = 1;
      int maxValue = nums[0];

      // 0,1,1,1,3,4,1,2,1,3,5,1,6,1,1,6,5,7,1,1,1,1,8

      for (int i = 1; i < L; i++) {
        maxCount += (nums[i] == maxValue) ? 1 : -1;

        if (maxCount == 0) {
          maxValue = nums[i + 1]; // guaranteed majority element, so no OOB exception
          maxCount = 1;
          i++;
        }
      }

      return maxValue;
    }
};

// time complexity: O(N)
// space complexity: O(1)
// algorithm: Boyer-Moore Voting Algorithm
