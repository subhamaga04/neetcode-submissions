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
    void traversal(TreeNode* root, int &count, int currMax){
        if(root == NULL) return; 

        if(root->val >= currMax){
            count++; 
            currMax = root->val; 
        }
        traversal(root->left,count, currMax);
        traversal(root->right,count, currMax);  

        return; 
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0; 
        int currMax = root->val; 
        traversal(root,count, currMax); 

        return count; 
    }
};
