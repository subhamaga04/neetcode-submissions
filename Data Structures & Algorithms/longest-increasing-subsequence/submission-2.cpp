class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result; 
        result.push_back(nums[0]); 

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > result.back()){
                result.push_back(nums[i]); 
            }else{
                int temp = lower_bound(result.begin(), result.end(), nums[i]) - result.begin();
                result[temp] = nums[i]; 
            }
        }

        return result.size();
    }
};
