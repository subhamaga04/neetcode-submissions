class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        priority_queue<int> pq;
        for (auto it : freq) {
            pq.push(it.second);
        }
        queue<pair<int, int>> q;
        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int remaining_freq = pq.top() - 1;
                pq.pop();
                if (remaining_freq > 0) q.push({remaining_freq, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
