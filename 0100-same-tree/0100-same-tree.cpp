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
    void bfs(TreeNode* root,vector<int>&arr){
        if(root==nullptr){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node==nullptr){
                    arr.push_back(67);
                    continue;
                }else{
                    arr.push_back(node->val);
                }
                if(node->left){
                    q.push(node->left);
                }else{
                    q.push(nullptr);
                }
                if(node->right){
                    q.push(node->right);
                }else{
                    q.push(nullptr);
                }
            }
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>arr1,arr2;
        bfs(p,arr1);
        for(auto n:arr1){
            cout<<n<<" ";
        }
        bfs(q,arr2);
        return arr1==arr2;
    }
};