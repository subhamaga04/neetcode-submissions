class Solution {
public:
    void func(string s, vector<string> &arr, int open, int close, int n){
        if(open == n && close == n){
            arr.push_back(s);
            return;  
        }

        if(open < n){
            func(s + "(", arr, open+1, close, n); 
        }
        if(close < open){
            func(s + ")", arr, open, close+1, n); 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        func("", arr, 0, 0, n); 

        return arr; 
    }
};
