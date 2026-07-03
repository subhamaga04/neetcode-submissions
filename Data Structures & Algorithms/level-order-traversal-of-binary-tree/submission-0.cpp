/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> arr1;
        if(root==NULL) return arr1;
        q.push(root);


        while (!q.empty()) {
            int size = q.size();
            vector<int> arr;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                arr.push_back(front->val);
                if (front->left != NULL) q.push(front->left);
                if (front->right != NULL) q.push(front->right);
            }
            arr1.push_back(arr);
        }
        return arr1;
    }
};
