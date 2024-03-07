class Solution {
public:
  int hammingDistance(int x, int y) {
    int found = 0;
    for (int i = 0; i < 32; i++) {
      int val = 1 << i;
      found += ((x & val) != (y & val)) ? 1 : 0;
    }
    return found;
  }
};

// topics: bit manipulation
// time complexity: O(1), space complexity: O(1)
