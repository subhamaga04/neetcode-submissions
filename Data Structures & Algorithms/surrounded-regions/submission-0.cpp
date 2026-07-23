class Solution {
private: 
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void dfs(int i, int j, vector<vector<char>>& board, int n, int m){
        board[i][j] = 'S';

        for(auto &it: directions){
            int newi = i + it[0]; 
            int newj = j + it[1]; 
            if(newi >= 0 && newj >=0 && newi < n && newj < m && board[newi][newj] != 'S' && board[newi][newj] == 'O'){
                dfs(newi , newj, board, n, m); 
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size(); 

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(i, 0, board, n, m); 
            if(board[i][m-1] == 'O') dfs(i, m-1, board, n, m); 
        }

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') dfs(0, j, board, n, m); 
            if(board[n-1][j] == 'O') dfs(n-1, j, board, n, m); 
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X'; 
                if(board[i][j] == 'S') board[i][j] = 'O'; 
            }
        }
    }
};
