class Solution {
private:
    void combi(int index, vector<int>& nums, int target, vector<int> &arr, vector<vector<int>> &arr1){
        if(target == 0){
            arr1.push_back(arr); 
            return; 
        }

        if(index >= nums.size() || target < 0) return; 

        arr.push_back(nums[index]); 
        combi(index, nums, target - nums[index], arr, arr1); 
        arr.pop_back(); 
        combi(index + 1, nums, target, arr, arr1); 

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> arr1; 
        vector<int> arr; 

        combi(0,nums,target,arr,arr1); 

        return arr1; 
    }
};
