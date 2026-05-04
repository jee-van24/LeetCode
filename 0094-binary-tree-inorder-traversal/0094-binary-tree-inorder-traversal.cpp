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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,bool>>st;
        if(root==nullptr)return {};
        vector<int>res;
        st.push({root,false});
        while(st.size()){
            auto [node,done]=st.top();
            st.pop();
            if(done){
                res.push_back(node->val);
                if(node->right){
                    st.push({node->right,false});
                }
            }else{
                st.push({node,true});
                if(node->left)
                st.push({node->left,false});
            }
        }
        return res;
    }
};