class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size()); 
        stack<int> st; 
        for(int i = 0; i< temp.size(); i++ ){
            while(!st.empty() && temp[st.top()] < temp[i]){
                int dis = i - st.top(); 
                ans[st.top()] = dis; 
                st.pop(); 
            }
            st.push(i); 
        }

        return ans; 
    }
};
