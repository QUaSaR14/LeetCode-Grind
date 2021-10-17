#include<bits/stdc++.h>
using namespace std;

// Premium Question : MST, DSU
// Problem Link : https://leetcode.ca/all/1168.html
// Solution Link : https://www.youtube.com/watch?v=gc6ShDTldb4

/*
    Since we need to water each house, we can either dig a well or get a pipe from some other house or well. 
    Now, if we were only asked to get minimum cost of pipes to connect all houses then we could have easily used MST.
    But, we also have to dig wells to first get water and then add pipes such that overall cost is minimized. 
    There can a case where digging well costs less than connecting pipes. Also, there can be some case where we can connect some pipes and some wells.
    So, we need to think smartly so that we get minimum cost to water all houses. 

    Idea here to first create a dummy node 0 and connect all houses to it such that edges weight [0--i] is equals to cost to dig well for house i.
    
    Ex : n = 3 , wells : [3, 5, 4] , then  
        0 --- 1 (3) , 0 --- 2 (5) , 0 --- 3 (4) 
    
    In this way, we have created a graph with nodes from 0 to n. And edges have weights as given. Now, this problem boils down to calculating MST cost.
    Also, we have taken into account pipes cost as well as well cost in newly created graph. 
    Use Kruskal's Algo to calculate minimum cost spanning tree (MST). 
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
        return true;
    }
};

class Node {
public: 
    int wt, u, v;
    Node(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

class Solution {
public: 
    static bool compare(const Node& a, const Node& b) {
        return a.wt < b.wt;
    }
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        // Kruskal Algo
        // Take dummy node 0 and connect with every node.
        // Edge weight 0-i will be cost to dig well i.e wells[i]
        vector<Node> edges;
        for(auto& pipe : pipes) {
            edges.push_back(Node(pipe[0], pipe[1], pipe[2]));
        }
        
        for(int i=0; i<n; i++) {
            edges.push_back(Node(0, i+1, wells[i]));
        }
        
        sort(edges.begin(), edges.end(), compare);
        
        DSU dsu(n);
        int cost = 0;
        
        for(auto& edge : edges) {
            if(dsu.unionBySize(edge.u, edge.v)) {
                cost += edge.wt;
            }
        }
        
        return cost;
    }
};