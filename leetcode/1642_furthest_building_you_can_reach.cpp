// Approach 1 - DP (My initial solution that works for moderate inputs)
/*
class Solution {
private:
  using vvvi = vector<vector<vector<int>>>;
  using vi = vector<int>;
public:
  int helper(const vi& h, int b, int l, int i, vvvi& dp) {
    if (i == h.size() - 1) {
      return 0;
    }

    int diff = h[i + 1] - h[i];
    if (b == 0 && l == 0 && diff > 0) {
      return 0;
    }

    if (dp[i][b][l] != -1) {
      return dp[i][b][l];
    }

    int up = -1, down = -1;
    if (diff > 0) {
      int brickWay = (b - diff) >= 0 ? helper(h, b - diff, l, i + 1, dp) : -1;
      int ladderWay = (l - 1) >= 0 ? helper(h, b, l - 1, i + 1, dp) : -1;
      up = max(brickWay, ladderWay);
    } else {
      down = helper(h, b, l, i + 1, dp);
    }

    dp[i][b][l] = 1 + max(up, down);
    return dp[i][b][l];
  }

  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    const int L = heights.size();
    vvvi dp(L, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));
    return helper(heights, bricks, ladders, 0, dp);
  }
};
*/

// Approach 2 - Priority Queue (the efficient one!)
class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    // to store the most bricks used in a jump of all time at every step
    priority_queue<int> jumps;
    const int L = heights.size();

    for (int i = 0; i < L - 1; i++) {
      int diff = heights[i + 1] - heights[i];
      if (diff <= 0) {
        continue;
      }

      // just assume you have enough bricks to jump at every step
      bricks -= diff;
      jumps.push(diff);

      // if bricks become negative, use a ladder to cover the biggest
      // jump between two steps and return the biggest jump back to bricks
      if (bricks < 0) {
        if (ladders <= 0) {
          return i;
        }
        bricks += jumps.top();
        jumps.pop();
        ladders -= 1;
      }
    }

    // if you have enough bricks/ladders available to jump at the last but one-th
    // step, you just made it to the last step! (0-indexed)
    return L - 1;
  }
};
