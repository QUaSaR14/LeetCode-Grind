#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int bfs(vector<vector<pair<int, int>>>& adj, int source, int threshold, const int& n) {
        int count = 0;
        
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        q.push({source, 0});
        
        while(q.size()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            vis[node] = true;
            
            if(distance > threshold) continue;
            
            for(auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                if(!vis[adjNode] and wt + distance <= threshold){
                    q.push({adjNode, wt + distance});
                    count++;                
                }
            }
        }
        
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int smallestNumOfNeighbours = n-1, city = n-1;
        
        for(int i=0; i<n; i++) {
            int count = bfs(adj, i, distanceThreshold, n);
            // cout << count << " " << i << endl;
            if(smallestNumOfNeighbours >= count) {
                smallestNumOfNeighbours = count;
                city = i;
            }
        }
        return city;
    }
};