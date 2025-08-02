class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        unordered_set<int> s(passengers.begin(), passengers.end());
        
        vector<pair<int, vector<int>>> data;
        int i = 0, j = 0;
        
        while (i < buses.size()) {
            int cap = 0;
            vector<int> curr;
            while (j < passengers.size() && passengers[j] <= buses[i] && cap < capacity) {
                curr.push_back(passengers[j]);
                cap++;
                j++;
            }
            data.push_back({buses[i], curr});
            i++;
        }

        int last_time = data.back().first;
        vector<int> last_bus_p = data.back().second;

        if (last_bus_p.size() < capacity) {
            for (int t = last_time; t >= 0; t--) {
                if (s.find(t) == s.end()) {
                    return t;
                }
            }
        } else {
            int last_p_time = last_bus_p.back();
            for (int t = last_p_time - 1; t >= 0; t--) {   
                if (s.find(t) == s.end()) {
                    return t;
                }
            }
        }

        return -1;
    }
};
