class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr=arr[0];
        if(k>=arr.size()){
            return *max_element(arr.begin(),arr.end());
        }
        int streak=0;
        bool flag=false;
        for(int i=1;i<arr.size();i++){
            if(curr>arr[i]){
                streak++;
            }else if(curr<arr[i]){
                streak=1;
                curr=arr[i];
            }
            if(streak==k){
                flag=true;
                return curr;
            }
        }
        if(!flag){
            return *max_element(arr.begin(),arr.end());
        }
        return 0;
        
    }
};