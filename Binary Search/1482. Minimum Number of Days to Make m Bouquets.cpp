#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool makeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int n = bloomDay.size();
        
        for(int i=0; i<n; ) {
            if(bloomDay[i] <= day) {
                int j = i+1, c = 1; 
                while(j<n && bloomDay[j] <= day && c < k) {
                    j++; c++;
                }
                if(c == k) cnt++;            
                i = j;
            }
            else {
                i++;
            }
        }
        return (cnt >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = 1, high = *max_element(begin(bloomDay), end(bloomDay));
        int ans = -1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(makeBouquets(bloomDay, mid, m, k)) {
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