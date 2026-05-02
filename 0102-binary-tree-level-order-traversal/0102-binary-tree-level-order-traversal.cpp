/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        res.push_back({root->val});
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            if (temp.size() != 0) {
                res.push_back(temp);
            }
        }
        return res;
    }
};