#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool travel(vector<int>& dist, int speed, double hour) {
        double time = 0.00;
        int n = dist.size();
        
        for(int i=0; i<n-1; i++) {
            time += ceil((double)dist[i] / speed);
            if(time > hour) return false;
        }
        
        time += (double)dist[n-1] / speed;
        
        return (time <= hour);
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int low = 1;
        int high = 1e7;
        
        int ans = -1;
        
        while(low <= high) {
            int mid = (low + ((high - low) >> 1));
            
            if(travel(dist, mid, hour)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};