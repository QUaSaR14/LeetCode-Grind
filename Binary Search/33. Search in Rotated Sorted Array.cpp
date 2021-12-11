#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int  lo = 0, hi = n-1;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if(nums[mid] == target) return mid;
            
            // if left part is sorted
            if(nums[lo] <= nums[mid]) {
                // if target lie either on left part
                if(target >= nums[lo] && target <= nums[mid]) {
                    hi = mid-1;
                }
                // else target lie on right part
                else {
                    lo = mid+1;
                }
            }
            // else right part is sorted
            else {
                // if target lie either on right part
                if(target >= nums[mid] && target <= nums[hi]) {
                    lo = mid+1;
                }
                // else target lie on left part
                else {
                    hi = mid-1;
                }
            }
        }
        
        return -1;
    }
};