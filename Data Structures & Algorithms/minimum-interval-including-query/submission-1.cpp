class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end()); 

        vector<vector<int>> queries_mp; 
        for(int i = 0; i < queries.size(); i++){
            queries_mp.push_back({queries[i], i}); 
        }

        sort(queries_mp.begin(), queries_mp.end()); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; 

        vector<int> ans(queries.size(), -1); 
        int j = 0; 

        for(int i = 0; i < queries_mp.size(); i++){

            while(j < intervals.size() && intervals[j][0] <= queries_mp[i][0]){
                if(queries_mp[i][0] <= intervals[j][1]){
                    int size = intervals[j][1] - intervals[j][0] +1; 
                    pq.push({size, intervals[j][1]}); 
                    
                }
                j++; 
            }

            while(!pq.empty() && pq.top().second < queries_mp[i][0]){
                pq.pop(); 
            }

            if(!pq.empty()){
                ans[queries_mp[i][1]] = pq.top().first;
            }
        }
        return ans; 
    }
};
