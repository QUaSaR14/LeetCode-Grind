#include<bit/stdc++.h>
using namespace std;

static int X[4] = {-1,0,0,1};
static int Y[4] = {0,-1,1,0};

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& end) {
        int n = maze.size();
        int m = maze[0].size(); 

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[start[0]][start[1]] = true;
        
        while(q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == end[0] && y == end[1]) return true;

            for(int k=0; k<4; k++) {
                int i = x;
                int j = y;

                // Roll(Move) untill we either reach a wall(1) or boundary of maze
                while(i>=0 && j>=0 && i<n && j<m && maze[i][j] == 0) {
                    i += X[k];
                    j += Y[k];
                }

                // After this line, either crosses the boundary or stopped at 1 (wall)
                // So, we need to take one step back as we have crossed.
                i -= X[k];
                j -= Y[k];

                if(!vis[i][j]) {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        return false;
    }
    
};