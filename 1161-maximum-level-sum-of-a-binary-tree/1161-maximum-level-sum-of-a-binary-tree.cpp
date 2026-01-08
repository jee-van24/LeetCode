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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int res=0;
        int sum=INT_MIN;
        if(!root)return 0;
        int currlevel=1;
        q.push(root);
        while(!q.empty()){
            int currsum=0;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* tree=q.front();
                q.pop();
                currsum+=tree->val;
                if(tree->left){
                    q.push(tree->left);
                }
                if(tree->right){
                    q.push(tree->right);
                }
            }
            if(currsum>sum){
                sum=currsum;
                res=currlevel;
            }
            currlevel++;
        }
        return res;
    }
};