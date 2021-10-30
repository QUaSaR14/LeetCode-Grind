#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);
        for(auto& seq : seqs) {
            for(int i=0; i<seq.size()-1; i++) {
                adj[seq[i]].push_back(seq[i+1]);
                indegree[seq[i+1]]++;
            }
        }
        
        queue<int> q;
        
        for(int i=1; i<=n+1; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int idx = 0;
        while(q.size()) {
            if(q.size() > 0) return false;
            
            int node = q.front(); q.pop();
            
            if(node != org[idx++]) return false;
            
            for(auto& adjnode : adj[node]) {
                if(--indegree[adjnode] == 0) q.push(adjnode);
            }
        }
        return idx == n;
    }
};