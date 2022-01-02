#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    bool subarrayWithMaxSum(vector<int>& nums, int maxSum, int m) {
        int n = 1, sum = 0;
        for(auto& num : nums) {
            if(num > maxSum) return false;
            
            if(sum + num > maxSum) {
                n++;
                sum = num;
            }
            else {
                sum += num;
            }
        }
        return (n <= m);
    }

public:
    
    int splitArray(vector<int>& nums, int m) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        int ans = high;
        
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(subarrayWithMaxSum(nums, mid, m)) {
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