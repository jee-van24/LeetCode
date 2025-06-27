class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curr_max=-1;
        int i=arr.size()-1;
        while(i>=0){
            int curr=arr[i];
            arr[i]=curr_max;
            curr_max=max(curr_max,curr);
            i--;
        }
        return arr;
    }
};