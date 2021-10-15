#include<bits/stdc++.h>
using namespace std;

// Premium Ques of DSU
// Problem Link : https://leetcode.ca/all/261.html
// Solution Link : https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/graph/261.-graph-valid-tree

/*
    A Graph is said to be a Tree if :
        1. Single Connected Component with n-1 edges fron n nodes
        2. No cycle 
    
    Thus we can use muliple approaches to solve this problem. Like DSU, DFS or BFS. 
    Here I have used DSU. In this, we will first check if parent of (u,v) are same or not. 
        i. If same this means there is a cycle in graph
        ii. Other wise we union(u,v) , and move to next edge. 
        iii.  Also we incrememnt count of total edges till now
    In the end we also check if there are total (n-1) edges or not. 
*/

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
    bool validTree(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n);
        for(auto& edge : edges) {
            if(!dsu.unionBySize(edge[0], edge[1])) return false;
        }
        return dsu.getCount() == 1;
    }
};
