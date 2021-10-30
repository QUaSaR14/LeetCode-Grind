#include<bits/stdc++.h>
using namespace std;

// Premium Ques : Topo Sort, BFS
// Problem Link : https://leetcode.ca/all/1136.html
// Solution Link : https://www.youtube.com/watch?v=KptcDjF92pE

class Solution {
public:
    
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);

        for(auto& relation : relations) {
            adj[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0, sem = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front(); q.pop();

                count ++;

                for(auto& adjnode : adj[node]) {
                    if(--indegree[adjnode] == 0) q.push(adjnode);
                }
            }
            sem ++;
        }

        return count == n ? sem : -1;
    }
};