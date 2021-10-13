#include<bits/stdc++.h>
using namespace std;

// Premium Ques 
// Refer this for question : https://leetcode.ca/all/1135.html
// Solution : https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/graph/1135.-connecting-cities-with-minimum-cost

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
    
    bool unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) return false;
        
        if(size[parU] <= size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
        count--;
        return true;
    }
    
    int getCount() {
        return count;
    }  
};

class Solution {
public: 
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        // [node, node, wt]

        sort(connections.begin(), connections.end(), compare);

        DSU dsu(n);
        int cost = 0;

        for(auto& conn : connections) {
            if(dsu.unionBySize(conn[0], conn[1])) {
                cost += conn[2];
            }
        }

        return dsu.getCount() == 1 ? cost : -1;
    }
};