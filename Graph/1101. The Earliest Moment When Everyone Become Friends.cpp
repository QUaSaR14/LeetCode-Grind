#include<bits/stdc++.h>
using namespace std;

// Premium Question : DSU, Sorting
// Problem Link : https://leetcode.ca/all/1101.html
// Solution Link : https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/graph/1101.-the-earliest-moment-when-everyone-become-friends

class DSU {
    vector<int> parent, size;
    int count;
public: 
    DSU(int n) {
        count = n;
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
        count--;
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public: 
    int earliestAcq(vector<vector<int>>& logs, int N) {
        
        DSU dsu(N);
        sort(logs.begin(), logs.end());
        
        // Union until only one single component is left.
        // That is the moment when everyone became friend
        for(auto& log : logs) {
            dsu.unionBySize(log[1], log[2]);
            if(dsu.getCount() == 1) return log[0];
        }
        
        return -1;
    }
};