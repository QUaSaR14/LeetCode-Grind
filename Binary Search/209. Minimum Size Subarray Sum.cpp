#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    bool check(vector<int>& arr, int k, int n, int x) {
        int sum = 0;
        
        for(int i=0; i<k; i++) sum += arr[i];
        
        if(sum >= x) return true;
        
        for(int i=k; i<n; i++) {
            sum += arr[i] - arr[i-k];
            if(sum >= x) return true;
        }
        
        return false;
    }
    
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0 || accumulate(nums.begin(), nums.end(), 0) < target) return 0;
        
        int lo = 1, hi = n;
        
        while(lo < hi) {
            int mid = (lo + hi) >> 1;
            
            if(check(nums, mid, n, target)) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        
        return lo;
    }
};