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
    void traversal(TreeNode* root, vector<int> &arr, int level){
        if(root == NULL){
            return; 
        }
        if(arr.size() == level){
            arr.push_back(root->val); 
        }

        traversal(root->right, arr, level + 1); 
        traversal(root->left, arr, level+1); 
    }    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr; 
        traversal(root, arr, 0); 

        return arr; 
        
    }
};
