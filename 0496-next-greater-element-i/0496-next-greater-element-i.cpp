class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>res(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                res[i]=-1;
                s.push(nums2[i]);
            }else if(nums2[i]<s.top()){
                res[i]=s.top();
                s.push(nums2[i]);
            }else{
                while(!s.empty()&&s.top()<=nums2[i]){
                    s.pop();
                }
                if(s.empty())res[i]=-1;
                else res[i]=s.top();
                s.push(nums2[i]);
            }
        }
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums2[i]]=res[i];
        }
        vector<int>a;
        for(int i=0;i<nums1.size();i++){
            a.push_back(map[nums1[i]]);
        }
        return a;
    }
};