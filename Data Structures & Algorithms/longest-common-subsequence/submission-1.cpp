class Solution {
   private:
    int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            int choice_1 = solve(text1, text2, i + 1, j, dp);
            int choice_2 = solve(text1, text2, i, j + 1, dp);
            return dp[i][j] = max(choice_1, choice_2);
        }

        return 0;
    }

   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(text1, text2, 0, 0, dp);
    }
};
