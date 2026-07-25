class DSU {
public: 
    vector<int> parent; 

    DSU(int n){
        parent.resize(n+1); 
        for(int i = 0; i < n+1; i++){
            parent[i] = i; 
        }
    }

    int find(int i){
        if(parent[i] == i) return i; 
        return parent[i] = find(parent[i]); 
    }

    bool unite(int u , int v){
        int root_u = find(u); 
        int root_v = find(v); 

        if(root_u == root_v) return false; 
       
        parent[root_v] = root_u;
        return true; 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        DSU dsu(n); 

        for(auto &edge : edges){
            if(dsu.find(edge[0]) == dsu.find(edge[1])) return {edge[0], edge[1]};
            else dsu.unite(edge[0], edge[1]); 
        }

        return {}; 
    }
};
