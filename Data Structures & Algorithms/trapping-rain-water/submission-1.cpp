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
                int unit = min(max_left, max_right) - height[left];
                if (unit > 0) total_unit += unit;
                left++;
                if (height[left] > max_left) max_left = height[left];
            }
            if (height[left] > height[right]) {
                int unit = min(max_left, max_right) - height[right];
                if (unit > 0) total_unit += unit;
                right--;
                if (height[right] > max_right) max_right = height[right];
            }
        }

        return total_unit;
    }
};
