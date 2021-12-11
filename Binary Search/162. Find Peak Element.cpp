#include<bits/stdc++.h>
using namespace std;

// Elimination of search space using proper induction
// i.e try to either eliminate left or right half (search space)
// And continue search on remaining half

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       
        int n = nums.size();
        
        int lo = 0, hi = n-1;
        
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            
            // if element at ith is greater than (i+1)th
            // We can surely say that peak will lie on LEFT HALF (high = mid)
            // Case 1 : Either all elements in left half are less, then ith is peak
            // Case 2 : Or there is some element on left of ith that is greater (i.e peak).
            if(nums[mid] > nums[mid+1]) {
                hi = mid;
            }
            // We can surely say that peak will lie on RIGHT HALF excluding mid (lo = mid+1)
            // Cases are same as above
            else {
                lo = mid+1;
            }
        }
        return lo;
    }
};