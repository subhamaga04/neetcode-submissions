class Solution {
   private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int& max_length) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        for (auto& it : directions) {
            int newi = it[0] + i;
            int newj = it[1] + j;

            if (newi >= 0 && newi < matrix.size() && newj >= 0 && newj < matrix[0].size()) {
                if (matrix[newi][newj] > matrix[i][j]) {
                    dp[i][j] = max(dp[i][j], 1 + dfs(matrix, dp, newi, newj, max_length));
                    max_length = max(max_length, dp[i][j]);
                }
            }
        }

        return dp[i][j] == -1 ? 1 : dp[i][j];
    }

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int max_length = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(matrix, dp, i, j, max_length);
            }
        }

        return max_length;
    }
};
