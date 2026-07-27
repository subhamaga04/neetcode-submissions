class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1); 

        for(auto &it : times){
            int u = it[0]; 
            int v = it[1]; 
            int w = it[2];
            adj[u].push_back({v,w}); 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

        vector<int> dist(n+1, INT_MAX); 
        dist[k] = 0; 

        pq.push({0,k}); 

        while(!pq.empty()){
            pair<int, int> p = pq.top(); 
            pq.pop(); 
            int d = p.first; 
            int u = p.second; 

            if(d > dist[u]) continue; 

            for(auto &it : adj[u]){
                int v = it.first; 
                int weight = it.second; 
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight; 
                    pq.push({dist[v], v}); 
                }
            }
        }

        int time = *max_element(dist.begin()+1, dist.end()); 
        return time == INT_MAX? -1 : time; 
    }
};
