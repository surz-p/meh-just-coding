class Solution {
public:
    struct MyMap {
      int n, f;
      MyMap(int x, int y) : n(x), f(y) {}
      bool operator<(const MyMap& rhs) { return f < rhs.f; }
    };

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      unordered_map<int, int> um;
      for (const auto& e : arr) {
        um[e]++;
      }

      vector<MyMap> vm;
      for (const auto& [k, v] : um) {
        vm.push_back({k, v});
      }

      sort(vm.begin(), vm.end());

      const int L = vm.size();
      int gone = 0;
      for (int i = 0; i < L; i++) {
        k = k - vm[i].f;
        gone += k >= 0 ? 1 : 0;
      }

      return L - gone;
    }
};

// topic: greedy
// time complexity: O(nlogn), space complexity: O(n)
// the time complexity can be reduced to O(n) by using counting sort
