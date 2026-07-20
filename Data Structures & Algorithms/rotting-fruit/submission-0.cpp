class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = grid.size();
        int m = grid[0].size();

        int minutes = 0;
        int foranges = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    foranges++;
                }
            }
        }

        if (foranges == 0) return 0;

        while (!q.empty() && foranges > 0) {
            int size = q.size();
            minutes++;
            for (int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (auto& it : directions) {
                    int newi = i + it[0];
                    int newj = j + it[1];
                    if (newi >= 0 && newj >= 0 && newi < n && newj < m) {
                        if (grid[newi][newj] == 1) {
                            q.push({newi, newj});
                            grid[newi][newj] = 2;
                            foranges--;
                        }
                    }
                }
            }
        }

        return foranges == 0 ? minutes : -1;
    }
};
