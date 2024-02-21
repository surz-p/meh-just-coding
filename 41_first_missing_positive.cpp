class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      const int L = nums.size();
      for (int i = 0; i < L; i++) {
        if (nums[i] <= 0) nums[i] = -(L + 1);
      }

      int idx = 0;
      for (int i = 0; i < L; i++) {
        if (nums[i] > 0) swap(nums[i], nums[idx++]);
      }

      if (idx == 0) return 1;


      for (int i = 0; i < L; i++) {
        int curr = abs(nums[i]);
        if (curr >= 1 && curr < idx) {
          nums[curr] = -abs(nums[curr]);
        } else if (curr == idx) {
          nums[0] = -abs(nums[0]);
        }
      }

      for (int i = 1; i < idx; i++) {
        if (nums[i] >= 0) {
          return i;
        }
      }

      if (nums[0] < 0) {
        return idx + 1;
      } else {
        return idx;
      }
    }
};

// topics: array, hash table
// time copmlexity: O(n), space complexity: O(1)
// HARD constraint: O(1) space
