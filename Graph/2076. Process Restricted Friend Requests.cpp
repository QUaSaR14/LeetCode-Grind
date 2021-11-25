#include<bits/stdc++.h>
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
    
    void unionBySize(int parU, int parV) {
        
        if(size[parU] < size[parV]) {
            size[parV] += size[parU];
            parent[parU] = parV;
        }
        else {
            size[parU] += size[parV];
            parent[parV] = parU;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        DSU dsu(n);
        
        vector<bool> successful;
        
        for(auto& request : requests) {
            
            int u = request[0], v = request[1];
            
            int parU = dsu.findParent(u), parV = dsu.findParent(v);
            
            bool flag = true;
            
            if(parU != parV) {
                
                for(auto& restriction : restrictions) {
                    int restricted_U = restriction[0], restricted_V = restriction[1];
                    
                    int restricted_parU = dsu.findParent(restricted_U);
                    int restricted_parV = dsu.findParent(restricted_V);
                    
                    if((parU == restricted_parU && parV == restricted_parV) || (parU == restricted_parV && parV == restricted_parU)) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag) {
                    dsu.unionBySize(parU, parV);
                }
            }
            
            successful.push_back(flag);
        }
        
        return successful;
    }
};