class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int distance=0;
        int n=colors.size();
        for(int i=0;i<colors.size();i++){
          if(colors[i]!=colors[0]){
            distance=max(distance,i);
          }
          if(colors[i]!=colors[n-1]){
            distance=max(distance,n-1-i);
          }
        }
        return distance;
    }
};