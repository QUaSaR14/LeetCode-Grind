#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool distributeBalls(vector<int>& position, int maxDis, int m) {
        int pos = position[0], cnt = 1;
        
        for(int i=1; i<position.size(); i++) {
            if(position[i] - pos >= maxDis) {
                cnt++;
                pos = position[i];
            }
        }
        return (cnt >= m);
    }
public:
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        
        sort(begin(position), end(position));
        
        int low = 1, high = position[n-1] - position[0];
        int ans = low;
        
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(distributeBalls(position, mid, m)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};