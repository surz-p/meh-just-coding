// Approach 1 (extra space)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      // positive nos. go from 0, 2, 4, ..., even(len(s)
      // negative nos. go from 1, 3, 5, ..., odd(len(s))

      const int L = nums.size();
      vector<int> pos, neg, res;
      pos.reserve(L / 2);
      neg.reserve(L / 2);
      res.reserve(L);

      for (const auto& e : nums) {
        if (e > 0) pos.push_back(e);
        if (e < 0) neg.push_back(e);
      }

      for (int i = 0; i < L / 2; i++) {
        res.push_back(pos[i]);
        res.push_back(neg[i]);
      }

      return res;
    }
};

// time complexity: ~O(n)
// space complexity: ~O(n)

// Approach 2 (constant space)
// ???