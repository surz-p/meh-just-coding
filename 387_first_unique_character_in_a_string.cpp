class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char, int> umap; // map char to index when seen for the first time
      int freq[26];
      memset(freq, 0, sizeof(freq));

      int len = s.size();
      for (int i = 0; i < len; i++) {
        if (umap.find(s[i]) == umap.end()) {
          umap[s[i]] = i;
        }
        freq[s[i] - 'a']++;
      }

      int val = INT_MAX;
      for (const auto& [k, v]: umap) {
        if (freq[k - 'a'] == 1) {
          val = min(val, v);
        }
      }

      return val == INT_MAX ? -1 : val;
    }
};

// topics: misc
// time complexity: O(n), space complexity: ~O(1)

