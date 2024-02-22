class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      // darn edge case *_*
      if (n == 1) {
        return 1;
      }

      int umap[1001];
      memset(umap, 0, sizeof(umap));
      int uset[1001];
      memset(uset, 0, sizeof(uset));

      for (const auto& vec : trust) {
        umap[vec[1]]++;
        uset[vec[0]]++;
      }

      for (int i = 1; i <= 1000; i++) {
        if (umap[i] == n - 1 && uset[i] == 0) {
          return i;
        }
      }

      return -1;
    }
};

// topics: array, hash table, graph???
// time complexity: O(n), space complexity: O(n)
