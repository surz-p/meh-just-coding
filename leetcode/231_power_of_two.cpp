class Solution {
public:
    bool isPowerOfTwo(int n) {
      return (n <= 0) || (n & n - 1) ? false : true;
    }
};

// topics: bit manipulation
// time complexity: O(1), space complexity: O(1)
