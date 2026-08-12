class Solution {
private: 
    bool solve(string &s1, string &s2, string &s3, int n, int m, int N, vector<vector<int>> &dp, int i, int j){
        if(i == n && j == m && i+j == N){
            return true; 
        }

        if(i+j >= N) return false; 

        if(dp[i][j] != -1) return dp[i][j]; 

        bool result_1 = false;
        bool result_2 = false; 

        if(i < n && s1[i] == s3[i+j]){
            result_1 = solve(s1, s2, s3, n, m , N, dp, i+1, j); 
        }
        if(j < m && s2[j] == s3[i+j]){
            result_2 = solve(s1, s2, s3, n, m , N, dp, i, j+1);
        }

        return dp[i][j] = result_1 || result_2; 

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(); 
        int m = s2.size();
        int N = s3.size(); 

        if(n + m != N) return false; 
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1)); 

        return solve(s1, s2, s3, n, m, N, dp, 0, 0); 

    }
};
