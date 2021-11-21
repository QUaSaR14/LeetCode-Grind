#include<bits/stdc++.h>
using namespace std;

// Solution : https://leetcode.com/problems/two-best-non-overlapping-events/discuss/1583776
// Similar to Weighted Job Scheduling Problem

class Solution {
public:
        
    int getNextIndex(vector<vector<int>>& events, int idx, const int& n) {
        
        int endTime = events[idx][1];
        
        int lo = idx+1, hi = n-1;
        
        int ans = n;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(events[mid][0] > endTime) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        
        return ans;
    }
    
    int attendEvents(vector<vector<int>>& events, vector<vector<int>>& dp, int idx, int k, const int& n) {
        if(k == 0 || idx == n) return 0;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        // Include : attend current event
        int nextIdx = getNextIndex(events, idx, n); 

        int incl = events[idx][2] + attendEvents(events, dp, nextIdx, k-1, n);
        
        // Exclude : skip current event
        int excl = attendEvents(events, dp, idx+1, k, n);
        
        return dp[idx][k] = max(incl, excl);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n = events.size(), k = 2;
        sort(events.begin(), events.end());
        
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    
        return attendEvents(events, dp, 0, k, n);
    }
};