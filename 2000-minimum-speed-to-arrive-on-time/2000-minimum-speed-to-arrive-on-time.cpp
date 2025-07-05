class Solution {
public:
    bool IsPossible(vector<int>&dist,int &speed,double hour){
        double total_time=0;
        for(int i=0;i<dist.size()-1;i++){
            int curr_dist=dist[i];
            total_time+=ceil((double)curr_dist/speed);
        }
        // for the last , need not wait as it is the last , so just add that time 
        total_time+=(double)dist[dist.size()-1]/speed;

        if(total_time>hour){
            return false;
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(IsPossible(dist,mid,hour)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }   
};