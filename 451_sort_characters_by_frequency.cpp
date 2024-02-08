class Solution {
private:
  struct Map {
    Map(char x, int y) : x(x), freq(y) {};
    char x;
    int freq;
  };
public:
    string frequencySort(string s) {
      string answer = "";
      vector<Map> vmap;
      unordered_map<char, int> umap;
      int len = s.size();

      for (int i = 0; i < len; i++) {
        umap[s[i]]++;
      }

      for (const auto& [k, v]: umap) {
        vmap.push_back(Map(k, v));
      }

      sort(vmap.begin(), vmap.end(), [](const Map& m, const Map& n){
        return m.freq > n.freq;
      });

      for (const auto& e : vmap) {
        answer.append(string(e.freq, e.x));
      }

      return answer;
    }
};
