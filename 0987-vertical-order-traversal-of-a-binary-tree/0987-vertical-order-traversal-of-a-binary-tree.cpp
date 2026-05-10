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
    void traverse(TreeNode* root,unordered_map<int,vector<pair<int,int>>>&map,int r,int c){
        if(root==nullptr)return;
        map[c].push_back({r,root->val});
        traverse(root->left,map,r+1,c-1);
        traverse(root->right,map,r+1,c+1);
    }
    int getHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        return 1+max(left,right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>>mp;
        vector<vector<int>>res;
        if(root==nullptr)return res;
        traverse(root,mp,0,0);
        int h=getHeight(root);
        for(int i=-h;i<=h;i++){
            if(mp.count(i)){
               auto &v=mp[i];
               map<int,vector<int>>temp;
               for(auto &p:v){
                temp[p.first].push_back(p.second);
               }
               vector<int>cols;
               for(auto &p:temp){
                    if(p.second.size()==1){
                        cols.push_back(p.second[0]);
                    }else{
                        sort(p.second.begin(),p.second.end());
                        for(auto n:p.second){
                            cols.push_back(n);
                        }
                    }
               }
               res.push_back(cols);
            }
        }
        return res;
    }
};