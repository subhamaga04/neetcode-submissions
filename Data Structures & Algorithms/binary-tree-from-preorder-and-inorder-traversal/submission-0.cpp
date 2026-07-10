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
    unordered_map<int, int> mp; 
    int pre_index = 0; 

    TreeNode* build(vector<int> &preorder, int start, int end){
        if(start > end){
            return NULL; 
        }

        TreeNode* root = new TreeNode(preorder[pre_index]); 
        int i = mp[preorder[pre_index]]; 
        pre_index++; 
        
        root->left = build(preorder, start, i-1); 
        root->right = build(preorder, i+1, end); 

        return root; 
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i; 
        }

        return build(preorder, 0, inorder.size()-1); 
    }
};
