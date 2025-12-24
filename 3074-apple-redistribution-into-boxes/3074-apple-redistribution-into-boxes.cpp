class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.rbegin(),apple.rend());
        sort(capacity.rbegin(),capacity.rend());
        int i=0,j=0;
        int res=1;
        while(i<apple.size()&&j<capacity.size()){
            while(i<apple.size()&&apple[i]<=capacity[j]){
                capacity[j]-=apple[i];
                i++;
            }
            while(j<capacity.size()&&i<apple.size()&&apple[i]>capacity[j]){
                res++;
                apple[i]-=capacity[j];
                j++;
            }

        }
        return res;
    }
};