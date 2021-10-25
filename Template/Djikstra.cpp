#include<bits/stdc++.h>
using namespace std;

class Djikstra {
public: 
    void djikstra(vector<vector<pair<int, int>>>& adj, int source, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n);

        dist[source] = 0;
        parent[source] = source;
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
                    parent[adjNode] = node;
                    pq.push({dis + wt, adjNode});
                }
            }
        }
    }
};