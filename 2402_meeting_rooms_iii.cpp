class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
      // keep a track of available rooms and used rooms
      // we want the number with the smallest room always, so min heap on available rooms
      // we want smallest ending time to pop first, so min heap on end times
      // also, we need to track which room has which interval - so pair (end_time, room)
      priority_queue<int
                     , vector<int>
                     , greater<int>> available;
      priority_queue<pair<long long, int>
                          , vector<pair<long long, int>>
                          , greater<pair<long long, int>>> used;

      // make all rooms available at the beginning
      for (int i = 0; i < n; i++) {
        available.push(i);
      }

      int counts[n];
      memset(counts, 0, sizeof(counts));

      sort(meetings.begin(), meetings.end());

      const int M = meetings.size();
      for (int i = 0; i < M; i++) {
        long long start = meetings[i][0], end = meetings[i][1];
        // check if any used intervals can be popped out at the starting time of meetings[i]
        // it is possible multiple meetings can end at same time, so use "while" not "if"
        while (!used.empty() && used.top().first <= start) {
          // some meeting from used should have ended before current meeting starts
          int roomThatEndsNow = used.top().second;
          used.pop();
          available.push(roomThatEndsNow); /* push room to available rooms */
        }

        // if no rooms are available
        if (available.empty()) {
          // make a room available
          auto [futureEndTime, room] = used.top();
          used.pop();
          available.push(room);
          end = futureEndTime + (end - start);
        }

        // if rooms are available
        int availableRoom = available.top();
        available.pop();
        used.push(pair<long long, int>{end, availableRoom});

        // increment the count in the counts array
        counts[availableRoom]++;
      }

      // determine which index has the highest meetings so far
      pair<int, int> maximus {-1, -1}; /* idx, max */
      for (int i = 0; i < n; i++) {
        if (counts[i] > maximus.second) {
          maximus.first = i;
          maximus.second = counts[i];
        }
      }

      return maximus.first;
    }
};

// topic: priority queue
// time complexity: O(mlogm + mlogn), space complexity: O(m + n)
