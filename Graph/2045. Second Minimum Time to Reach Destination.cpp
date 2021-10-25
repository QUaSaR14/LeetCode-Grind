#include<bits/stdc++.h>
using namespace std;

// Refer this : https://www.youtube.com/watch?v=BPCT3TmOKGo

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> adj(n+1);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> timeTaken(n+1, INT_MAX);
        vector<int> visCount(n+1, 0);

        int source = 1, destination = n;
        timeTaken[source] = 0;
        visCount[source]++;
        pq.push({0, source});

        int cnt = 0;
        while(pq.size()) {
            int currTime = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(node == destination) {
                cnt++;
                if(cnt == 2) return currTime;
            }
            
            int signal = currTime / change;
            
            if(signal & 1) {
                currTime += (change * (signal+1) - currTime);
            }

            for(auto& adjNode : adj[node]) {
                if(visCount[adjNode] < 2 and currTime + time != timeTaken[adjNode]) {
                    visCount[adjNode]++;
                    timeTaken[adjNode] = currTime + time;
                    pq.push({currTime + time, adjNode});
                }
            }
        }   
        return -1;
    }
};