class Solution {
public:
    bool isHappy(int n) {
        int result = 0; 
        while(n != 1){
            
            while(n!= 0){
                int digit = n %10; 
                result+= digit*digit; 
                n /= 10; 
            }
            if(result == 1) return true;
            if(result == 4) return false; 
            n = result;
            result = 0; 
        }

        return true; 
    }
};
