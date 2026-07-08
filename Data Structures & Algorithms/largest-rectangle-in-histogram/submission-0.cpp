class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_height = 0; 
        stack<int> st; 
        heights.push_back(0); 
        int left_boundary, right_boundary; 
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                right_boundary = i; 
                int hc = st.top(); 
                st.pop(); 
                if(st.empty()) left_boundary = -1; 
                else left_boundary = st.top(); 
                int high = (right_boundary - left_boundary - 1) * heights[hc];
                max_height = max(max_height, high); 
            }
            st.push(i); 
        }

        return max_height; 
    }
};
