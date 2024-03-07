class Solution {
public:
    using pii = pair<int, int>; // shorthand notation
    int networkDelayTime(vector<vector<int>>& T, int n, int k) {
      // reserve space for constructing edges
      vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));

      // initialize times to reach any node as INT_MAX (infinity)
      vector<int> times(n + 1, INT_MAX);
      times[k] = 0;

      // construct edges
      const int TT = T.size();
      for (int i = 0; i < TT; i++) {
        graph[T[i][0]][T[i][1]] = T[i][2];
      }

      // queue for bfs - holds pair({timeTakenToReachNode, Node})
      queue<pii> qu;
      qu.push({0, k});

      // loop
      while (!qu.empty()) {
        // keep track of how many vertices are in the current level
        const int S = qu.size();
        // for each vertex ...
        for (int x = 0; x < S; x++) {
          auto [val, node] = qu.front();
          qu.pop();
          // for all neighbours of vertex ...
          for (int j = 1; j <= n; j++) {
            // check if there is a path and if going this route is less expensive
            if (graph[node][j] >= 0 && times[j] > val + graph[node][j]) {
            // update the new time taken and push the neighbour to explore newer paths
              times[j] = min(times[j], val + graph[node][j]);
              qu.push({times[j], j});
            }
          }
        }
      }

      // find the least time (meaning: max time in our solution)
      // i.e., no smaller than this
      int res = -1;
      for (int i = 1; i <= n; i++) res = max(res, times[i]);
      // if there are disconnected components, or vertices with no invward paths
      // they will never be reached!
      return res == INT_MAX ? -1 : res;
    }
};

// topics: graph, shortest path, dijkstra
// time complexity: O(V^2), space complexity: O(V^2)
