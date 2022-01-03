#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int mod = 1e9 + 7;
        
        int n = nums1.size();
        
        set<int> nums(begin(nums1), end(nums1));
        
        long long diffSum = 0, maxDiff = 0;
        
        for(int i=0; i<n; i++) {
            long long diff = abs(nums1[i] - nums2[i]);
            diffSum += diff;
            
            if(maxDiff < diff) {
                auto it = nums.lower_bound(nums2[i]);
                if(it != begin(nums)) {
                    maxDiff = max(maxDiff, diff - abs(*prev(it) - nums2[i]));
                }
                if(it != end(nums)) {
                    maxDiff = max(maxDiff, diff - abs(*it - nums2[i]));
                }
            }
        }
        
        return (diffSum - maxDiff) % mod;
    }
};