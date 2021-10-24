#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<int> stops(n, k+1);
        stops[src] = 0;
        
        pq.push({0, {0, src}});
        
        while(pq.size()) {
            int cost = pq.top().first;
            int stopsTillNow = pq.top().second.first;
            int node = pq.top().second.second;
            
            pq.pop();
            
            if(node == dst) return cost;
            
            if(stopsTillNow <= k and stops[node] >= stopsTillNow) {
                stops[node] = stopsTillNow;
            
                for(auto& it : adj[node]) {
                    int adjNode = it.first;
                    int wt = it.second;
                    pq.push({cost + wt, {stopsTillNow + 1, adjNode}});
                }    
            } 
        }
        
        return -1;
    }
};