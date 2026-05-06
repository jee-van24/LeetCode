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
        int left=calc(root->left,res);//sum from the left subtree
        int right=calc(root->right,res);//sum from the right subtree
        //there can be 3 cases 
        //1.The sum from left and right + currval can be the max
        int all3=left+root->val+right;
        //2.if both left and right sum hinder ur sum , then just return root->val;
        int justroot=root->val;
        //3.either u can include sum of leftsubtree , or sum of the right subtree and that is what u will return to the further recursive calls
        int eitherone=max(left,right)+root->val;
        //now update res
        res=max({res,all3,justroot,eitherone});
        return max(eitherone,justroot);
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        calc(root,res);
        return res;
    }
};