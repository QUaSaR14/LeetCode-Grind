#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int source = 0;
        
        vector<int> dist(n, maxMoves + 1);
        
        dist[source] = 0;
        
        pq.push({0, source});
                
        while(pq.size()) {
            auto [dis, node] = pq.top();
            
            pq.pop();
                        
            for(auto& it : adj[node]) {
                auto [adjnode, cnt] = it;
                cnt++;
                
                if(dis + cnt < dist[adjnode]) {
                    dist[adjnode] = dis + cnt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        
        int nodesVis = 0;
        for(auto& d : dist) {
            if(d <= maxMoves) nodesVis++;
        }
        
        for(auto& edge : edges) {
            int forward = max(0, maxMoves - dist[edge[0]]);
            int backward = max(0, maxMoves - dist[edge[1]]);
            
            nodesVis += min(edge[2], forward + backward);
        }
        
        return nodesVis;
    }
};