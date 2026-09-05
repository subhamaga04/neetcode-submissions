class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
       bool target_i = false, target_j = false, target_k = false; 

       for(auto &it : triplets){
            bool isSafe = true; 

            for(int r = 0; r < target.size(); r++){
                if(target[r] < it[r]) isSafe = false; 
            }

            if(isSafe){
                if(target[0] == it[0]) target_i = true; 
                if(target[1] == it[1]) target_j = true; 
                if(target[2] == it[2]) target_k = true; 

                bool check = target_i && target_j && target_k; 
                if(check) return true; 
            }
       } 


       return false; 
    }
};
