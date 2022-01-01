#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool check(vector<int>& nums, int val, int threshold) {
        int sum = 0;
        for(auto& num : nums) {
            sum += (num / val);   
            if(num % val) sum++;
        }
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
     
        int n = nums.size();
        
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int ans = hi;
        
        while(lo <= hi) {
            int mid = lo + ((hi-lo) >> 1);
            // cout << lo << " " << hi << endl;
            if(check(nums, mid, threshold)) {
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