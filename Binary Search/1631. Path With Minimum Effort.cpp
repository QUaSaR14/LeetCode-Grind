#include<bits/stdc++.h>
using namespace std;

static int X[4] = {0, 0, 1, -1};
static int Y[4] = {1, -1, 0, 0};

class Solution {
private:
    bool bfs(vector<vector<int>>& grid, int threshold) {
        
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        vis[0][0] = true;
                
        while(q.size()) {
            auto [x, y] = q.front(); q.pop();
                        
            if(x == m-1 && y == n-1) return true;
            
            for(int k=0; k<4; k++) {
                int i = x + X[k];
                int j = y + Y[k];
                
                if(i >= 0 && j >= 0 && i < m && j < n && !vis[i][j]) {
                    if(abs(grid[i][j] - grid[x][y]) <= threshold) {
                        vis[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int low = 0, high = 1e6;
        int ans = low;
        
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            
            if(bfs(heights, mid)) {
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