class Solution {
   private:
    bool ispalin(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; 
            right--; 
        }
        return true;
    }

    void collect(int index, string s, vector<vector<string>>& ans, vector<string>& curr) {
        if (index >= s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (ispalin(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                collect(i + 1, s, ans, curr);
                curr.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        collect(0, s, ans, curr);

        return ans;
    }
};
