class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        vector<int> result(len, 0);
        stack<pair<int, int>> dMonoStack;

        dMonoStack.push(pair<int, int>{temp[len - 1], len - 1});
        for (int i = len - 2; i >= 0; --i) {
            if (temp[i] < dMonoStack.top().first) {
                dMonoStack.push(pair<int, int>{temp[i], i});
            } else {
                while(!dMonoStack.empty() && temp[i] >= dMonoStack.top().first) {
                    pair<int, int> p = dMonoStack.top();
                    dMonoStack.pop();
                    result[p.second] = dMonoStack.empty() ?
                                        0 : dMonoStack.top().second - p.second;
                }
                dMonoStack.push(pair<int, int>{temp[i], i});
            }
        }

        while (!dMonoStack.empty()) {
            pair<int, int> p = dMonoStack.top();
            dMonoStack.pop();
            result[p.second] = dMonoStack.empty() ?
                                0 : dMonoStack.top().second - p.second;
        }

        return result;
    }
};

// topics: monotonic stack
// time complexity: O(n), space complexity: O(n)
