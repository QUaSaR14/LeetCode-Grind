#include<bit/stdc++.h>
using namespace std;

// DFS Based Solution
class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node) {
        vis[node] = true;
        
        for(auto& adjNode : adj[node]) {
            if(!vis[adjNode]) {
                dfs(adj, vis, adjNode);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        
        vector<vector<int>> adj(n);
        for(auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        vector<bool> vis(n, false);
        int components = 0;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(adj, vis, i);
                components++; 
            }
        }
        
        return components-1;
    }
};

// UNION-FIND Based solution

class DSU {
    vector<int> parent, size;
    int count;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        count = n;
    }
    
    int findParent(int num) {
        if(parent[num] == num) return num;
        return parent[num] = findParent(parent[num]);
    }
    
    void unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) return;
        
        if(size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
        count--;
    }
    
    int getCount() {
        return count;
    }
    
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        
        if(m < n-1) return -1;
        
        DSU dsu(n);
        
        for(auto& connection : connections) {
            dsu.unionBySize(connection[0], connection[1]);
        }
        
        return dsu.getCount() - 1;
    }
};