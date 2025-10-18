class ExamTracker {
public:
    vector<int> times;
    vector<long long> scoresums;

    ExamTracker() {}

    void record(int time, int score) {
        times.push_back(time);
        if (scoresums.empty())
            scoresums.push_back(score);
        else
            scoresums.push_back(score + scoresums.back());
    }

    long long totalScore(int startTime, int endTime) {
        int n = times.size();

        // lower bound: first exam >= startTime
        int low = 0, high = n - 1, lowerbnd = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(times[mid] >= startTime){
                lowerbnd = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // upper bound: first exam > endTime
        low = 0; high = n - 1;
        int upperbnd = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(times[mid] > endTime){
                upperbnd = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int actualupperbnd = upperbnd - 1;
        if(lowerbnd > actualupperbnd) return 0;

        if(lowerbnd==0){
            return scoresums[actualupperbnd];
        }else{
            return scoresums[actualupperbnd]-scoresums[lowerbnd-1];
        }
    }
};
