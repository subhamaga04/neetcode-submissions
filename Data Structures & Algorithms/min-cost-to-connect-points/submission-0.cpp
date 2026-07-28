class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        vector<bool> inMst(n, false); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

        int minCost = 0; 
        pq.push({0,0});

        while(!pq.empty()){
            pair<int, int> p = pq.top(); 
            pq.pop(); 

            int weight = p.first; 
            int u = p.second; 

            if(!inMst[u]){
                inMst[u] = true; 
                minCost+= weight; 

                for(int v = 0 ; v < n; v++){
                    if(v == u || inMst[v]) continue; 
                    
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]); 
                    pq.push({cost, v});
                }
            }
        }
        return minCost; 
    }
};
