#include<bits/stdc++.h>
using namespace std;

class Solution {
public:  
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);
        
        int i=0;
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], succProb[i]});
            adj[edge[1]].push_back({edge[0], succProb[i]});
            i++;
        }
        
        priority_queue<pair<double, int>> pq;
        
        vector<double> probability(n, 0.00);
        probability[start] = 1;
        
        pq.push({1, start});
        
        while(pq.size()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(node == end) return prob;
            
            for(auto& it : adj[node]) {
                int adjNode = it.first;
                double wt = it.second;
                
                double newProb = prob * wt;
                
                if(newProb > probability[adjNode]) {
                    probability[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }
        return 0.00;
    }
};