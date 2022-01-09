#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    bool pairDist(vector<int>& nums, int maxDiff, int k) {
        int n = nums.size();
        int count = 0, j = 0;
        
        for(int i=0; i<n; i++) {
            while(j < n && nums[j] - nums[i] <= maxDiff) j++;
            
            count += (j - i - 1);
        }
        return (count >= k);
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));
        
        int low = 0, high = *max_element(begin(nums), end(nums));
        int ans = low;
        while(low <= high) {
            int mid = (high + low) >> 1;
            
            if(pairDist(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};