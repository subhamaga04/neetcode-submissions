class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 

        int fresh_fruit = 0;
        queue<pair<int, int>> rotten;
        int minutes = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh_fruit++;
                }
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        if(fresh_fruit == 0 ) return 0; 
        // if(rotten.empty()) return -1; 

        while (!rotten.empty() && fresh_fruit > 0) {
            int size = rotten.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> p = rotten.front();
                rotten.pop();
                int r = p.first;
                int c = p.second;
                for (auto& it : directions) {
                    int nr = it[0] + r;
                    int nc = it[1] + c;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            rotten.push({nr, nc});
                            fresh_fruit--;
                        }
                    }
                }
            }
            minutes++;
        }

        return fresh_fruit == 0 ? minutes : -1;
    }
};
