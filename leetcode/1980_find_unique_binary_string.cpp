class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
      string s = "";
      const int L = nums.size();
      for (int i = 0; i < L; i++) {
        s.append(nums[i][i] == '0' ? string(1, '1') : string(1, '0'));
      }

      return s;
    }
};

// topics: bit manipulation, algorithm, cantor's diagonal argument
// time complexity: O(n), space complexity: O(1)
// important constraints for this to work
/*
Constraints:
n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/
