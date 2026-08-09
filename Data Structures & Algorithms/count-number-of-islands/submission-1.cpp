class Solution {
   private:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[i][j] = true;

        for (auto& it : directions) {
            int new_i = it[0] + i;
            int new_j = it[1] + j;
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size()) {
                if(!visited[new_i][new_j] && grid[new_i][new_j] == '1'){
                    dfs(new_i, new_j, visited, grid); 
                }
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid);
                    count++;
                }
            }
        }

        return count;
    }
};
