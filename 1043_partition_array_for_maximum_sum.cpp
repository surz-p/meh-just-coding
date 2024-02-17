class Solution
{
public:
    int helper(const int &ws, const vector<int> &arr, int l, int r, vector<int> &dp)
    {
        if (l == r)
        {
            dp[l] = arr[l];
            return arr[l];
        }

        if (dp[l] != -1)
        {
            return dp[l];
        }

        int maxSum = 0;
        int currMax = arr[l];

        int wsPossible = min(ws, r - l + 1);

        for (int i = 1; i <= wsPossible; i++)
        {
            currMax = max(currMax, arr[l + i - 1]);
            int currRes = currMax * i;
            int nextRes = (l + i) <= r ? helper(ws, arr, l + i, r, dp) : 0;
            maxSum = max(maxSum, currRes + nextRes);
        }

        dp[l] = maxSum;
        return maxSum;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int len = arr.size();
        vector<int> dp(len, -1);
        return helper(k, arr, 0, len - 1, dp);
    }
};
