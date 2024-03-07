class Solution {
public:
    bool isPalindrome(const string& s) {
      int l = 0, r = s.size() - 1;
      while (l <= r) {
        if (s[l] != s[r]) {
          return false;
        }
        l++; r--;
      }
      return true;
    }
    string firstPalindrome(vector<string>& words) {
      const int L = words.size();
      for (int i = 0; i < L; i++) {
        if (isPalindrome(words[i])) {
          return words[i];
        }
      }
      return "";
    }
};

// time complexity: O(N * M)
// space complexity: O(1)
