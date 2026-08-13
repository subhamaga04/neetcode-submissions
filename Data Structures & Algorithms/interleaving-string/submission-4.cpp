class Solution {
private: 
    bool solve(string &s1, string &s2, string 
    &s3,  vector<vector<int>> &dp, int n, int m, int N, int i, int j){
        if(i == n && j == m && i+j == N) return true; 

        if(i+j >= N) return false; 

        if(dp[i][j] != -1) return dp[i][j]; 

        bool result1 = false; 
        bool result2 = false; 

        if(i < n && s1[i] == s3[i+j]){
            result1 = solve(s1, s2, s3, dp, n, m, N, i+1, j); 
        }

        if(j < m && s2[j] == s3[i+j]){
            result2 = solve(s1, s2, s3, dp, n, m, N, i, j+1); 
        }

        return dp[i][j] = result1 || result2; 
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(); 
        int m = s2.size(); 
        int N = s3.size(); 
        if(n + m != N) return false; 

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1)); 

        return solve(s1, s2, s3, dp, n, m, N, 0, 0); 
    }
};
