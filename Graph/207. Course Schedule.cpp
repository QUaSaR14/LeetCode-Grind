#include<bit/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);    
            indegree[pre[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int completedCourses = 0;
        
        while(q.size()) {
            int node = q.front(); q.pop();
            completedCourses++;
            
            for(auto& it : adj[node]) {
                indegree[it]--;
                
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return completedCourses == numCourses;
    }
};