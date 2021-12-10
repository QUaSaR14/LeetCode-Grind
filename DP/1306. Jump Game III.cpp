#include<bits/stdc++.h>
using namespace std;

// Approach 1: DFS
class Solution {
public:
    
    bool dfs(vector<int>& a, vector<bool>& vis, int idx, int n) {
        
        if(a[idx] == 0) return true;
        if(vis[idx]) return false;
        
        vis[idx] = true;
        
        // Move right
        if( idx + a[idx] < n) if(dfs(a, vis, idx + a[idx], n)) return true;
        
        // Move left
        if( idx - a[idx] >= 0) if(dfs(a, vis, idx - a[idx], n)) return true;
        
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<bool> vis(n, false);
        return dfs(arr, vis, start, n);
    }
};

// Approach 2: BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
     
        int n = arr.size();
        
        vector<int> vis(n, 0);
        
        queue<int> q;
        
        q.push(start);
        
        while(q.size()) {
            int idx = q.front(); q.pop();
            
            vis[idx] = true;
            
            if(arr[idx] == 0) return true;
            
            if(idx + arr[idx] < n && !vis[idx + arr[idx]]) q.push(idx + arr[idx]);
            if(idx - arr[idx] >= 0 && !vis[idx - arr[idx]]) q.push(idx - arr[idx]);
        }
        
        return false;
    }
};