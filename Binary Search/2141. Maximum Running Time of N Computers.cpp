#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool runComp(vector<int>& batt, long long limit, long long m) {
        long long net = (long long)(limit * m);
        
        for(auto& i : batt) {
            net -= min((long long)i, limit);
            if(net <= 0) return true;
        }
        return false;
    } 
public:
    long long maxRunTime(int n, vector<int>& batt) {
        
        long long low = 0, high = accumulate(begin(batt), end(batt), 0LL);
        long long ans = low;
        while(low <= high) {
            long long mid = (high + low) >> 1;
            
            if(runComp(batt, mid, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }  
        return ans;
    }
};