class Solution {
private: 
    vector<vector<int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};  
    bool find(int index, int i , int j, vector<vector<char>>& board, string &word){
        if(index == word.size()) return true; 

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#' || board[i][j] != word[index]) return false; 

        char temp = board[i][j]; 
        board[i][j] = '#'; 

        for(auto &dir : directions){
            int neoi = i + dir[0]; 
            int neoj = j + dir[1]; 

            if(find(index+1, neoi, neoj, board, word)) return true; 

        }

        board[i][j] = temp; 
        return false; 

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && find(0, i, j, board, word)) return true; 
            }
        }

        return false; 
    }
};
