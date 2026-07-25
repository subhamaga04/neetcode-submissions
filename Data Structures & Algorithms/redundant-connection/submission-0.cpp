class Solution {
private: 
    bool isreachable(int src, int target, vector<vector<int>> &adj,  vector<bool> &visited){
        if(target == src){
            return true; 
        }

        visited[src] = true; 

        for(auto &it : adj[src]){
            if(!visited[it]){
                if(isreachable(it, target, adj, visited)) return true; 
            }
        }

        return false; 
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<vector<int>> adj(n+1); 

        for(auto &edge : edges){
            vector<bool> visited(n+1, false); 

            int u = edge[0]; 
            int v = edge[1]; 

            if(isreachable(u, v, adj, visited)) return {u,v}; 

            adj[u].push_back(v); 
            adj[v].push_back(u); 

        }

        return {}; 
    }
};
