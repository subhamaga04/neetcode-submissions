class Solution {
   private:
    int func(vector<int>& nums, vector<int>& dp, int n) {
        if (n == 0 || n == 1) return nums[n];

        if (dp[n] != -1) return dp[n];

        int a = 0;

        if (n - 2 >= 0) {
            a = func(nums, dp, n - 2);
        }

        int b = 0;

        if (n - 3 >= 0) {
            b = func(nums, dp, n - 3);
        }

        return dp[n] = nums[n] + max(a, b);
    }

   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        vector<int> dp(n, -1);

        int a = max(func(nums1, dp, nums1.size() - 1), func(nums1, dp, nums1.size() - 2));

        fill(dp.begin(), dp.end(), -1);

        int b = max(func(nums2, dp, nums2.size() - 1), func(nums2, dp, nums2.size() - 2));

        return max(a, b);
    }
};
