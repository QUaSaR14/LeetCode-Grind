#include<bits/stdc++.h>
using namespace std;

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
    
    int getSize(int n) {
        return size[n];
    }
};
class Solution {
public:
    
    bool check(string& a, string& b) {
        int swaps = 0;
        for(int i=0; i<a.size(); i++) {
            if(a[i] != b[i] && ++swaps > 2) return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        
        DSU dsu(n);
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(check(strs[i], strs[j])) {
                    dsu.unionBySize(i, j);
                }
            }
        }
        return dsu.getCount();
    }
};