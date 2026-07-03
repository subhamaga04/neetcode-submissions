class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> boss; 
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i< nums.size(); i++){
           if(i > 0 && nums[i] == nums[i-1]) continue; 
           int left = i + 1; 
           int right = nums.size()-1; 
           int target = 0 - nums[i]; 
           while(left < right){
                vector<int> arr;
                if(nums[left] + nums[right] == target){
                    arr.push_back(nums[i]); 
                    arr.push_back(nums[left]); 
                    arr.push_back(nums[right]); 
                    boss.push_back(arr); 
                    left++; 
                    right--; 
                    while(left < right && nums[left] == nums[left-1]){
                        left++; 
                    }
                     while(left < right && nums[right] == nums[right+1]){
                        right--; 
                    }
                }else if(nums[left] + nums[right] < target) left++; 
                else right--; 
           } 
        }
        return boss; 
    }
};
