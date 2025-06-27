class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int distance=0;
        for(int i=0;i<colors.size();i++){
            for(int j=i+1;j<colors.size();j++){
                if(colors[i]!=colors[j]){
                    distance=max(distance, abs(i-j));
                }
            }
        }
        return distance;
    }
};