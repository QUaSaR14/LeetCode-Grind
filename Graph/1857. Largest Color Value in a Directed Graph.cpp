#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i]-'a']++;
            }
        }
        
        int maxColorVal = 0, vis = 0;
        
        while(q.size()) {
            int node = q.front(); q.pop();
            
            int val = *max_element(dp[node].begin(), dp[node].end());
            
            maxColorVal = max(maxColorVal, val);
            
            vis++;
            
            for(auto& adjnode : adj[node]) {
                
                for(int i=0; i<26; i++) {
                    dp[adjnode][i] = max(dp[adjnode][i], dp[node][i] + (i == colors[adjnode]-'a'));
                }
                
                if(--indegree[adjnode] == 0) q.push(adjnode);
            }
        }
        
        return vis == n ? maxColorVal : -1;
    }
};