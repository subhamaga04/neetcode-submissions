class Solution {
private: 
    void get_permute(int index, vector<vector<int>> &ans, vector<int> &nums){
        if(index == nums.size() -1){
            ans.push_back(nums); 
            return; 
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]); 
            get_permute(index+1, ans, nums); 
            swap(nums[index], nums[i]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        get_permute(0, ans, nums); 
        return ans; 
    }

};
