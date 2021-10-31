#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
     
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto& relation : relations) {
            adj[relation[0]-1].push_back(relation[1]-1);
            indegree[relation[1]-1]++;
        }
        
        queue<int> q;
        vector<int> endTime(n, 0);
    
        for(int i=0; i<n; i++) {
            endTime[i] = time[i];
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int finishTime = 0;
       
        while(q.size()) {

            int node = q.front(); q.pop();
            for(auto& adjnode : adj[node]) {
                endTime[adjnode] = max(endTime[adjnode], endTime[node] + time[adjnode]);
                if(--indegree[adjnode] == 0) q.push(adjnode);
            }
            
            finishTime = max(finishTime, endTime[node]);
        }
        
        return finishTime;
    }
};