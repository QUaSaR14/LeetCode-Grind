#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        long long mod = (1e9 + 7);
        vector<long long> ways(n, 0);
        vector<long long> dist(n, 1e18);
        
        dist[0] = 0;
        ways[0] = 1;
        
        vector<pair<long long, long long>> adj[n];
        for(auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        
        pq.push({0, 0});
        
        while(pq.size()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            
            pq.pop();
            
            for(auto& it : adj[node]) {
                long long adjNode = it.first;
                long long wt = it.second;
                
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dis + wt, adjNode});
                }
                else if(dis + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};