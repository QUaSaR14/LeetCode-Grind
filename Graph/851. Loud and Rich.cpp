#include<bits/stdc++.h>
using namespace std;

/**
 * Approach 1: using BFS (topo sort)
*/

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto& rich : richer) {
            adj[rich[0]].push_back(rich[1]);
            indegree[rich[1]]++;
        }
        
        queue<int> q;
        vector<int> answer(n);
        
        for(int i=0; i<n; i++) {
            answer[i] = i;
            if(indegree[i] == 0) q.push(i);
        }
        
        while(q.size()) {
            int node = q.front(); q.pop();
            
            for(auto& adjNode : adj[node]) {
                if(quiet[answer[adjNode]] > quiet[answer[node]]) {
                    answer[adjNode] = answer[node];
                }
                
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        return answer;
    }
};

/**
 * Approach 2: using DFS 
*/

class Solution {
public:
    
    int dfs(vector<vector<int>>& adj, vector<int>& quiet, vector<int>& ans, int node) {
        if(ans[node] != -1) return ans[node];
        
        ans[node] = node;
        for(auto& adjnode : adj[node]) {
            int ans_adjnode = dfs(adj, quiet, ans, adjnode);
            
            if(quiet[ans_adjnode] < quiet[ans[node]]) {
                ans[node] = ans_adjnode;
            }
        }
        
        return ans[node];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        
        vector<vector<int>> adj(n);

        for(auto& rich : richer) {
            adj[rich[1]].push_back(rich[0]);
        }
        
        vector<int> answer(n, -1);
        
        for(int i=0; i<n; i++) {
            dfs(adj, quiet, answer, i);
        }
        
        return answer;
    }
};