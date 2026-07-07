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
private: 
    bool check(TreeNode* root, long long minima, long long maxima){
        if(root == NULL) return true; 

        if(root -> val <= minima || root-> val >= maxima) return false;

        return check(root->left, minima, root->val) && check(root->right, root->val, maxima); 
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root->left, LLONG_MIN, root->val)&& check(root->right, root->val, LLONG_MAX); 
        
    }
};
