#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = n-1;
        
        while(lo <= hi) {
            int mid = (hi + lo) >> 1;
            
            if(nums[mid] < nums[hi]) hi = mid;
            else if(nums[mid] > nums[hi]) lo = mid+1;
            else hi--;
        }
        
        return nums[lo];
    }
};