#include<bit/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findParent(int num) {
        if(parent[num] == num) return num;
        return parent[num] = findParent(parent[num]);
    }
    
    void unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) return;
        
        if(size[parU] <= size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
    
    int getSize(int i) {
        return size[i];
    }
};

class Solution {
public:
    
    bool canCommunicate(const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first == b.first || a.second == b.second);
    }
    
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = grid[0].size();
        
        vector<pair<int, int>> connected;
        int cnt = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    connected.push_back({i, j});
                    cnt++;
                }
            }
        }
        
        DSU dsu(cnt);
                
        for(int i=0; i<cnt; i++) {
            for(int j=i+1; j<cnt; j++) {
                if(canCommunicate(connected[i], connected[j])) {
                    dsu.unionBySize(i, j);
                }
            }
        }
        
        int servers = 0;
        
        for(int i=0; i<cnt; i++) {
            if(dsu.findParent(i) == i && dsu.getSize(i) > 1) {
                servers += dsu.getSize(i);
            }
        }
        
        return servers;
    }
};