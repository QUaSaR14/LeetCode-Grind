#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/discuss/1097359/

class Solution {
    int mod = 1e9 + 7;
public:
    
    int restrictedPaths(vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& dp, int node, const int& n) {
        if(node == n) return 1;
        
        if(dp[node] != -1) return dp[node];
        
        int paths = 0;
        
        for(auto& it : adj[node]) {
            if(dist[it.first] < dist[node]) {
                paths = (paths + restrictedPaths(adj, dist, dp, it.first, n)) % mod;
            }
        }
        
        return dp[node] = paths;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        int source = n, destination = 1;
        
            
        dist[source] = 0;
        pq.push({0, source});

        while(pq.size()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();

            for(auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                }
            }
        }
        
        vector<int> dp(n+1, -1);
        return restrictedPaths(adj, dist, dp, destination, n);
    }
};