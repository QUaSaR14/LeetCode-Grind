#include<bits/stdc++.h>
using namespace std;

class Solution {
    int distribute(vector<int>& quantities, int val) {
        int count = 0;
        
        for(auto& quantity : quantities) {
            count += (quantity / val) + (quantity % val > 0);
        }

        return count;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        
        int ans = hi;
        
        while(lo <= hi) {
            int mid = lo + ((hi-lo) >> 1);

            if(distribute(quantities, mid) <= n) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        
        return ans;
    }
};