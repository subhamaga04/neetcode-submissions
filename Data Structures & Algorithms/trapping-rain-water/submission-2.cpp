class Solution {
   public:
    int trap(vector<int>& height) {
        // two pointers
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_left = height[left];
        int max_right = height[right];
        int total_unit = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                max_left = max(max_left, height[left]); 
                total_unit += max_left - height[left]; 
                left++;
               
            }
            else{
                max_right = max(max_right, height[right]); 
                total_unit += max_right - height[right]; 
                right--;
                
            }
        }

        return total_unit;
    }
};
