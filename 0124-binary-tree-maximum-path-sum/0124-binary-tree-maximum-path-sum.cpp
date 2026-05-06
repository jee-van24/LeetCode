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
    int calc(TreeNode* root,int &res){
        if(root==nullptr)return 0;
        int left=max(0,calc(root->left,res));//sum from the left subtree
        int right=max(0,calc(root->right,res));//sum from the right subtree
        int all3=left+right+root->val;
        res=max(res,all3);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        calc(root,res);
        return res;
    }
};