#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int isPossible(long long idx, long long a, long long maxSum, long long n) {
        long long i = idx, j = n - idx - 1;
        long long b = a - 1, leftSum = 0, rightSum = 0;
        
        if(i < b) {
            leftSum = (b * (b + 1)) / 2 - ((b - i) * (b - i + 1)) / 2;
        } 
        else {
            leftSum = (b * (b + 1)) / 2 + (i - b);
        }
        
        if(j < b) {
            rightSum = (b * (b + 1)) / 2 - ((b - j) * (b - j + 1)) / 2;
        } 
        else {
            rightSum = (b * (b + 1)) / 2 + (j - b);
        }
        
        long long sum = a + leftSum + rightSum;
        return (sum <= maxSum);
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum;
        long long ans = low;
        
        while(low <= high) {
            long long mid = low + ((high - low) >> 1);
            
            if(isPossible(index, mid, maxSum, n)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};