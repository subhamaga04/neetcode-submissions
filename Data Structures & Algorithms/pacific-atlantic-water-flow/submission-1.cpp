class Solution {
private: 
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1}, {0,-1}}; 
    void dfs(int i, int j, vector<vector<bool>> &mapy, vector<vector<int>>& heights){

        mapy[i][j] = true; 

        for(auto &it: directions){
            int newi = i + it[0]; 
            int newj = j + it[1]; 
            if(newi >= 0 && newj >= 0 && newi < heights.size() && newj < heights[0].size() && !mapy[newi][newj] && heights[newi][newj] >= heights[i][j]){
                dfs(newi, newj, mapy, heights); 
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(); 
        int m = heights[0].size(); 
        
        vector<vector<int>> result; 
        
        vector<vector<bool>> pacific(n, vector<bool> (m, false)); 
        vector<vector<bool>> atlantic(n, vector<bool> (m, false)); 

        for(int i = 0; i < n; i++){
            dfs(i, 0, pacific, heights); 
        }
        for(int j = 0; j < m ;j++){
            dfs(0, j, pacific, heights); 
        }
        for(int i = 0; i < n; i++){
            dfs(i, m-1, atlantic, heights); 
        }
        for(int j = 0; j < m ;j++){
            dfs(n-1, j, atlantic, heights); 
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vector<int> point(2); 
                    point[0] = i; 
                    point[1] = j; 
                    result.push_back(point); 
                }
            }
        }

        return result; 

    }
};
