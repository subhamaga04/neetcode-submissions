class Solution {
private: 
    vector<vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1}}; 
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited, int &area, int &m, int &n){
        if(i < 0 || j < 0 || i >= n || j>=m || visited[i][j] || grid[i][j] != 1) return; 

        visited[i][j] = true; 
        area++; 

        for(auto &it : directions){
            int newi = i + it[0]; 
            int newj = j + it[1]; 
            dfs(newi , newj, grid, visited, area, m, n); 
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<bool>> visited(n, vector<bool> (m,false));
        int max_area = 0; 
        int area = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    area = 0; 
                    dfs(i, j, grid, visited, area, m, n);
                    max_area = max(area, max_area); 
                }
            }
        }

        return max_area; 

    }
};
