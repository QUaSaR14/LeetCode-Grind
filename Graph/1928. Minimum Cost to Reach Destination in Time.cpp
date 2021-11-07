#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<int> fees(n, INT_MAX), travelTime(n, INT_MAX);
        
        int source = 0, destination = n-1;
  
        fees[source] = passingFees[source];
        travelTime[source] = 0;
                        
        pq.push({passingFees[0], {0, source}});
        
        while(pq.size()) {
            int cost = pq.top().first;
            int time = pq.top().second.first;
            int node = pq.top().second.second;
            
            // cout << node << " : " << cost << " : " << time << endl;
            
            pq.pop();
            
            if(node == destination) return cost;
            
            for(auto& it : adj[node]) {
                int adjnode = it.first;
                int currTime = it.second;
                
                if(currTime + time <= maxTime) {
                 
                    if(time + currTime < travelTime[adjnode]) {
                        travelTime[adjnode] = time + currTime;
                        pq.push({cost + passingFees[adjnode], {travelTime[adjnode], adjnode}});
                    } 
                    else if(cost + passingFees[adjnode] < fees[adjnode]) {
                        fees[adjnode] = cost + passingFees[adjnode];
                        pq.push({fees[adjnode], {travelTime[adjnode] + time, adjnode}});
                    }
                }
            }
            
        }
        
        return -1;
    }
};