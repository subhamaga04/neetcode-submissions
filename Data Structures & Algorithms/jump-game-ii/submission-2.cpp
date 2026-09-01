class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0; 
        int curr_end = 0; 
        int jump = 0; 
        for(int i = 0; i < n - 1; i++){

            farthest = max(farthest, i + nums[i]); 

            if(i == curr_end){
                curr_end = farthest; 
                jump++; 
            }
        }

        return jump; 
    }
};
