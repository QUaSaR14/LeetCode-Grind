#include<bits./stdc++.h>
using namespace std;

static int X[4] = {-1, 0, 0, 1};
static int Y[4] = {0, -1, 1, 0};

class Solution {
public:
    int shortestDist(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<int> distance(n*m + 1, INT_MAX);

        distance[start[0]*m + start[1]] = 0;
        pq.push({0, {start[0], start[1]}});

        while(pq.size()) {
            int dis = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == destination[0] && y == destination[1]) return dis;

            for(int k=0; k<4; k++) {
                int i = x, j = y, wt = 0;
                while(i>=0 && j>=0 && i<n && j<m && maze[i][j] == 0) {
                    i += X[k];
                    j += Y[k];
                    wt++;
                }

                i -= X[k];
                j -= Y[k];
                wt--;

                int node = i*m + j;
                if(dis + wt < distance[node]) {
                    distance[node] = dis + wt;
                    pq.push({dis + wt, {i, j}});
                }
            }
        }
        return -1;
    }
};