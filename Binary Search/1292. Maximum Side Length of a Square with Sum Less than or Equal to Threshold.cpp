#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkSquare(vector<vector<int>>& dp, int k, int threshold, const int& m, const int& n) {
        for(int i=k; i<=m; i++) {
            for(int j=k; j<=n; j++) {
                int sum = dp[i][j] + dp[i-k][j-k] - dp[i-k][j] - dp[i][j-k];
                
                if(sum <= threshold) return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        int low = 0, high = min(m, n);
        int ans = 0;
        
        while(low <= high) {
            int mid = (low + high) >> 1;
            
            if(checkSquare(dp, mid, threshold, m, n)) {
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