class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> inMst(n + 1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});
        int connected = 0;
        int total_cost = 0;
        while (!pq.empty() && connected < n) {
            pair<int, int> p = pq.top();
            int u = p.second;
            int d = p.first;
            pq.pop();

            if (!inMst[u]) {
                inMst[u] = true;
                total_cost += d;
                connected++;
                for (int v = 0; v < n; v++) {
                    if (v == u || inMst[v]) continue;

                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return total_cost;
    }
};
