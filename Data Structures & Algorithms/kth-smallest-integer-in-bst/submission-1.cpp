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
    void find(TreeNode* root, int k , int &count, int &value){
        if(root == NULL || count >= k){
            return; 
        }

        find(root->left, k, count, value); 
        count++; 
        if(count == k){
            value = root -> val; 
            return; 
        }
        if(count < k) find(root->right, k, count, value); 
    }    
public:
    int kthSmallest(TreeNode* root, int k) {
        int value = 0; 
        int count = 0; 
        find(root, k, count, value); 
        return value; 
    }
};
