class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        vector<vector<int>> result;
        for (auto point : points) {
            double distance = sqrt(((point[0] - 0) * (point[0] - 0)) +
                                ((point[1] - 0) * (point[1] - 0)));
            pair<double, vector<int>> a = {distance, point};
            pq.push(a);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        int size = pq.size(); 
        for (int i = 0; i < size; i++) {
            result.push_back(pq.top().second);
            pq.pop();

        }

        return result;
    }
};