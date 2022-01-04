#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canDivideBalls(vector<int>& nums, int limit, int m) {
        int ops = 0;
        for(auto& num : nums) {
            ops += (num / limit) - (num % limit == 0);
        }
        
        return (ops <= m);
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int low = 1, high = *max_element(begin(nums), end(nums));
        int ans = high;
        
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(canDivideBalls(nums, mid, maxOperations)) {
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