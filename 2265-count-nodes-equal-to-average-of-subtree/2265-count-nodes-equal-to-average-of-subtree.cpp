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
    int Count(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int count=1;
        if(root->left){
            count+=Count(root->left);
        }
        if(root->right){
            count+=Count(root->right);
        }
        return count;
    }
    int sum(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int s=0;
        if(root->left){
            s+=sum(root->left);
        }
        if(root->right){
            s+=sum(root->right);
        }
        return s+root->val;
    }
    void  explore(TreeNode* root,int &res){
        if(root==nullptr){
            return;
        }
        int lefts=0,rights=0;//sum of the left and right subtree
        int count=Count(root);//counting total number of nodes in this subtree 
        if(root->left){
            lefts=sum(root->left);//sum of the left subtree 
        }
        if(root->right){
            rights=sum(root->right);
        }
        //total sum of this subtree is 
        int tot=lefts+rights+root->val;
        if(tot/count==root->val){
            res++;
        }
        if(root->left){
            explore(root->left,res);
        }
        if(root->right){
            explore(root->right,res);
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int res=0;

        explore(root,res);
        return res;
    }
};