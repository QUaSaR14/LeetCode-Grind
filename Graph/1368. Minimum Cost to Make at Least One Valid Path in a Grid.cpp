#include<bits/stdc++.h>
using namespace std;

static int X[4] = {0, 0, 1, -1};
static int Y[4] = {1, -1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = grid[0].size();
        
        vector<vector<pair<int, int>>> adj(m*n);
        
        /*
            Construct Graph by converting 2D -> 1D. So, say (i,j) = i*n + j = u
            If there is a sign from nth node to its adjacent then cost to move is 0. 
                * Thus edge wt will be 0 for u -> v
            
            Otherwise, edge weight will be 1. Since we have to modify sign in that direction to move.
                * Edge wt will be 1 for u -> v
        */
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int u = i*n + j;
                for(int k=0; k<4; k++) {
                    int x = i + X[k];
                    int y = j + Y[k];
                
                    int v = x*n + y;
                    if(x>=0 && y>=0 && x<m && y<n) {
                        if(grid[i][j] == k+1) {
                            adj[u].push_back({v, 0});
                        } 
                        else {
                            adj[u].push_back({v, 1});
                        }
                    }
                }
            }
        }
        
        // Simply do 0-1 BFS to find shortest distance from source=0 to destionation=m*n-1
        deque<pair<int, int>> dq;
        vector<int> dist(m*n + 1, INT_MAX);
        
        int source = 0, destination = m*n - 1;
        
        dist[source] = 0;
        dq.push_front({source, 0});
        
        
        while(dq.size()) {
            int node = dq.front().first;
            int dis = dq.front().second;
            
            dq.pop_front();
            
            if(node == destination) return dis;
            
            for(auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = wt + dis;
                    if(wt == 1) {
                        dq.push_back({adjNode, dis + wt});
                    } 
                    else {
                        dq.push_front({adjNode, dis + wt});
                    }
                }
            }
        }
        
        return -1;
    }
};