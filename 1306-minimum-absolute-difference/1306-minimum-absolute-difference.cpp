class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        int diff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            int curr_diff=abs(arr[i]-arr[i-1]);
            if(curr_diff<diff){
                res.clear();
                res.push_back({arr[i-1],arr[i]});
                diff=curr_diff;
            }
            else if(curr_diff==diff){
                res.push_back({arr[i-1],arr[i]});

            }
            else{
                continue;
            }
            
        }
        return res;

    }
};