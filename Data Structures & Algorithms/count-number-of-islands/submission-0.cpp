class Solution {
private: 
    vector<vector<int>> directions = {{1,0},{-1,0}, {0,1},{0,-1}}; 
    void dfs(int i, int j, vector<vector<char>>& grid,  vector<vector<bool>> &visited){
        if(i < 0 || j< 0 || i>= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] != '1') return; 

        visited[i][j] = true; 
        for(auto &it : directions){
            int newI = i + it[0]; 
            int newJ = j + it[1]; 
            dfs(newI, newJ, grid, visited); 
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false)); 
        int count = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++; 
                    dfs(i, j, grid, visited); 
                }
            }
        }

        return count; 
    }
};
