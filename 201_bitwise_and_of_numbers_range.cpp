class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      if (left == 0) return 0;
      if (left == right) {
        return left;
      }

      int trueLeft = 0;

      int count = 0;
      for (int i = 0; i < 32; i++) {
        // check if any power is in the non-inclusive boundary (left, right)
        // if yes, & of all lower and higher values is 0
        int val = 1 << i;
        if (val > left && val < right) {
          return 0;
        }

        // if no power is in non-inclusive boundary (left, right),
        // check if power is equals to left or right
        if (val == left || val == right) { // the max value of count can be 2
          count++;
          // required for displaying answer
          trueLeft = val == left ? val : 0;
        }
      }

      cout << count;
      if (count == 0) {
        // not a single power was found in the inclusive boundary [left, right],
        // return & of the interval for e.g., 6, 7 -> 0b110
        int r = left;
        for (int i = left; i < right; i++) { // <--- O(n) killer!!!
          r &= (i + 1);
        }
        return r;
      }

      if (count == 2) {
        // both left and right are powers of 2,
        // return 0 for e.g., 0b0100, 0b0010 -> 0b0000
        return 0;
      }

      // count is 1 and if that is on left boundary, then it is the answer
      // count is 1 and if that is not on left boundary, then 0
      return (trueLeft != 0) ? trueLeft : 0;
    }
};

// topics: bit manipulation
// time complexity: O(n), space complexity: O(1)
// can be optimized to O(1) time complexity
