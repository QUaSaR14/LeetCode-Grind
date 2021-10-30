#include<bits/stdc++.h>
using namespace std;

/**
 * Approach 1 : using BFS (Topo Sort)
 * 
 * Trick here is to reverse direction of all edges. And then perform simple topo sort.
 * Reversing edges will help us in classifying TERMINAL NODES => indegree is zero
 * Also, doing topo sort will exclude all nodes that are present in a cyclic path.  
 * So, topo sort will give us the all nodes that are either terminal or there is a path to terminal nodes.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        int i = 0;
        for(auto& g : graph) {
            for(auto& it : g) {
                adj[it].push_back(i);
                indegree[i]++;
            }
            i++;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> safeNodes;
        
        while(q.size()) {
            int node = q.front(); q.pop();
            
            safeNodes.push_back(node);
            
            for(auto& adjnode : adj[node]) {
                if(--indegree[adjnode] == 0) q.push(adjnode);
            }
        }
    
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};