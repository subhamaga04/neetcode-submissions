class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); 

        for(auto &it : flights){
            int u = it[0]; 
            int v = it[1]; 
            int w = it[2]; 
            adj[u].push_back({v,w});
        }

        vector<int> dist(n, INT_MAX); 
        dist[src] = 0; 

        queue<vector<int>> q; 

        q.push({src, 0,-1}); 

        while(!q.empty()){
            vector<int> p = q.front(); 
            int u = p[0]; 
            int d = p[1]; 
            int stops = p[2]; 

            q.pop(); 

            if(stops > k) continue; 

            for(auto &it : adj[u]){
                int v = it.first; 
                int weight = it.second; 
                if(d + weight < dist[v] && stops + 1 <= k){
                    dist[v] = d + weight; 
                    q.push({v, dist[v], stops+1}); 
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst]; 

    }
};
