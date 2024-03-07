class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vector<int>>;
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vvi result(len / 3, vi());

        for (int i = 0; i < len; i++) {
            if (i % 3 == 0) {
                result[i / 3].push_back(nums[i]);
            } else {
                if (nums[i] - result[i / 3][0] <= k) {
                    result[i / 3].push_back(nums[i]);
                } else {
                    return vvi();
                }
            }
        }
        
        return result;
    }
};

// topics: greedy
// time complexity: O(nlogn), space complexity: O(n)

