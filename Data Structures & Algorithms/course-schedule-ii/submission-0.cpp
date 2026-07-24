class Solution {
private: 
    bool isCycle(int src,  vector<int> &order,  vector<bool> &visited,  vector<bool> &recPath,  vector<vector<int>> &adj){

        visited[src] = true; 
        recPath[src] = true; 

        for(auto &it : adj[src]){
            if(!visited[it]){
                if(isCycle(it, order, visited, recPath, adj)) return true; 
            }else if(recPath[it]) return true; 
        }

        order.push_back(src);
        recPath[src] = false; 
        return false; 

    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses; 
        vector<vector<int>> adj(n); 

        for(auto &it :  prerequisites){
            int u = it[0]; 
            int v = it[1]; 
            adj[v].push_back(u); 
        }


        vector<bool> visited(n, false); 
        vector<bool> recPath(n, false); 
        vector<int> order; 

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(isCycle(i, order, visited, recPath, adj)) return {}; 
            }
        }

        reverse(order.begin(), order.end()); 

        return order; 

    }
};
