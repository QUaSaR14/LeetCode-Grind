#include<bits/stdc++.h>
using namespace std;

/*
    Idea here is connect all cities with values greater than threshold with its multiples. Till it is less than n.
    Ex : Threshold = 2, n = 20 => i = 3 to n
    3 -- 3*m , where m = 1,2,3 .... such that 3*m <= 20
    4 -- 4*m , where m = 1,2,3 .... such that 4*m <= 20
    In general, connect (i -- i*m) , j = 1,2,3.... such that i*m <= n

    Now, that we have built the DSU with all connections made, we just need to find if nodes given in query belong to same component or not. 
    i.e parent[i] == parent[j], where queries[k] = {i, j}
*/

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
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        DSU dsu(n);
        
        for(int i=threshold+1; i<=n; i++) {
            int j = 1;
            while(i*j <= n) {
                dsu.unionBySize(i, i*j);
                j++;
            }
        }
        
        vector<bool> res;
        for(auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            if(dsu.findParent(u) == dsu.findParent(v)) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};