class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0; 
        int count_10 = 0; 

        for(int &it : bills){
            if(it == 5) count_5++; 
            else if(it == 10){
                if(count_5 < 1){
                    return false; 
                }
                count_5--; 
                count_10++; 
            }else{
                if(count_10 >= 1 && count_5 >= 1){
                    count_10--; 
                    count_5--; 
                }else if(count_5 >= 3){
                    count_5 -= 3; 
                }else return false; 
            }
        }

        return true; 
    }
};