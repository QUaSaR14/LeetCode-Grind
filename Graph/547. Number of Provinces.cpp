#include<bit/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(i);
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
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        DSU dsu(n);
        
        int count = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isConnected[i][j]) {
                    if(dsu.findParent(i) != dsu.findParent(j)) {
                        dsu.unionBySize(i, j);
                    }
                }
            }
        }
        
        int components = 0;
        
        for(int i=0; i<n; i++) {
            if(dsu.findParent(i) == i)
                components++;
        }
        
        return components;
    }
};