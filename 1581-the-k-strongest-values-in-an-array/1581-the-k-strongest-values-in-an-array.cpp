class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int>res;
        int left=0,right=arr.size()-1,n=arr.size();
        int mid= arr[(n-1)/2];
        while(res.size()<k&&left<=right){
            int left_strength=fabs(arr[left]-mid);
            int right_strength=fabs(arr[right]-mid);
            if(left_strength>right_strength||(left_strength==right_strength)&&arr[left]>arr[right]){
                res.push_back(arr[left]);
                left++;
            }else{
                res.push_back(arr[right]);
                right--;
            }

        }
        return res;
    }
};