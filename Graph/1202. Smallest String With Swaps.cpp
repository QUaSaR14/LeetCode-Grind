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
    
    void unionByValue(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) {
            return;
        }
        
        if(size[parU] < size[parV]) {
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        
        DSU dsu(n);
        
        for(auto& pair : pairs) {
            dsu.unionByValue(pair[0], pair[1]);
        }
        
        unordered_map<int, vector<int>> groups;
        
        for(int i=0; i<n; i++) {
            int par = dsu.findParent(i);
            groups[par].push_back(i);
        }
        
        for(auto& group : groups) {
            string str = "";
            for(auto& idx : group.second) str += s[idx];
            sort(str.begin(), str.end());
            int i = 0;
            for(auto& idx : group.second) s[idx] = str[i++];
        }
        
        return s;
    }
};