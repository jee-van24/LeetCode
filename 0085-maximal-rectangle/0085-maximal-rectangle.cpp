class Solution {
public:
    int largarea(vector<int>&nums){
        stack<vector<int>>s;
        vector<int>prev(nums.size(),0),next(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty()&&s.top()[1]>nums[i]){
                s.pop();
            }
            if(s.empty()){
                next[i]=nums.size();
            }else{
                next[i]=s.top()[0];
            }
            s.push({i,nums[i]});
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<nums.size();i++){
            while(!s.empty()&&s.top()[1]>=nums[i]){
                s.pop();
            }
            if(s.empty()){
                prev[i]=-1;
            }else{
                prev[i]=s.top()[0];
            }
            s.push({i,nums[i]});
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            int left=prev[i]+1;
            int right=next[i]-1;
            int len=right-left+1;
            int area=nums[i]*len;
            res=max(res,area);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>psum;
        vector<int>arr(matrix[0].size(),0);
        for(int i=0;i<matrix[0].size();i++){
            arr[i]=matrix[0][i]-'0';
        }
        psum.push_back(arr);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                arr[j]=(matrix[i][j]!='0')?(matrix[i][j]-'0')+psum[i-1][j]:0;
            }
            psum.push_back(arr);
        }
        int res=0;
        for(auto &v:psum){
            res=max(res,largarea(v));
        }
        
        return res;
    }
};