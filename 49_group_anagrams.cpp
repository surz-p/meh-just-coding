#define FORRS(cont) for (const auto &e : cont)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> result;
      const int len = strs.size();
      vector<string> mapper(len, string(26, '0'));

      for (int i = 0; i < len; i++) {
        // strs[i] find the mapping of chars of this string
        const int nowLen = strs[i].size();
        for (int j = 0; j < nowLen; j++) {
          mapper[i][strs[i][j] - 'a']++;
        }
      }

      unordered_map<string, vector<string>> umap;
      for (int i = 0; i < len; i++) {
        // strs and mapper are now mapped together
        if (umap.find(mapper[i]) == umap.end()) {
          umap[mapper[i]] = vector<string> {strs[i]};
        } else {
          umap[mapper[i]].push_back(strs[i]);
        }
      }

      FORRS(umap) {
        result.push_back(e.second);
      }

      return result;
    }
};
