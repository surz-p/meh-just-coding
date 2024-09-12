class Solution {
public:
    int countSubstrings(string s) {
      // ABBA -> IF EVEN, LEN(S) + 1 CAN NEVER BE A PALINDROME
      // ABCBA -> IF ODD, LEN(S) + 1 CAN NEVER BE A PALINDROME
      // HYPOTHESIS: IF LEN(PAL) = X, NEXT POSSIBLE PALINDROME LEN = X + 2
      int count = 0;

      const int L = s.size();
      for (int i = 0; i < L; i++) {
        // single point dive
        int l = i, r = i;
        while (l >= 0 && r < L) {
          if (s[l] == s[r]) {
            count++;
            l--; r++;
            continue;
          }
          break;
        }
      }

      for (int i = 0; i < L - 1; i++) {
        // double point dive
        int l = i, r = i + 1;
        while (l >= 0 && r < L) {
          if (s[l] == s[r]) {
            count++;
            l--; r++;
            continue;
          }
          break;
        }
      }

      return count;
    }
};

// time complexity: O(N^2)
// space complexity: O(1)