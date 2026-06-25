class Solution {
public:
    bool isPalindrome(string s) {
        string result; 
        for(char ch : s){
            if(isalnum(ch)){
                result += tolower(ch); 
            }
        }
        int left = 0; 
        int right = result.length()-1; 

        while(left<right){
            if(result[left] != result[right]){
                return false; 
            }
            left++; 
            right--; 
        }
        return true; 
    }
};
