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
    void traverse(TreeNode* curr,vector<int>&res){
        if(curr==nullptr){
            return;
        }
        traverse(curr->left,res);
        traverse(curr->right,res);
        res.push_back(curr->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        traverse(root,res);
        return res;
    }
};