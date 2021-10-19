#include<bit/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
    int count = 0;
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
        
        if(size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
        count++;
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
     
        int n = stones.size();
        DSU dsu(n);
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dsu.unionBySize(i, j);
                }
            }
        }
        
        return dsu.getCount();
    }
};