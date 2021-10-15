#include<bits/stdc++.h>
using namespace std;

// Premium Question : DSU
// Problem link : https://leetcode.ca/all/305.html
// Solution Link : https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/graph/305.-number-of-islands-ii

/*
    Idea here is to convert 2D -> 1D and do union-find for each given positions with its adjacent nodes.
    Also, we keep track of count of unions performed. So, to get total no. of islands at a given time, 
    we simply subtract count from total ones (1) occured till now. This gives us no. of islands. 
    Also refer Number of Islands I problem, to get more detail. 
*/

static int X[4] = {-1, 0, 0, 1};
static int Y[4] = {0, -1, 1, 0};

class DSU {
    vector<int> parent, size;
    int count;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        count = 0;
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
        count++;
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public: 
    vector<int> numIslands2(int m, int n, vector<vector<int> >& positions) {
        
        DSU dsu(m*n);
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        vector<int> res;
        int islands = 0;
        for(auto& pos : positions) {
            int i = pos[0];
            int j = pos[1];
            
            if(grid[i][j] == 0) {
                grid[i][j] = 1;
                islands++;

                int u = i*n + j;
                for(int k=0; k<4; k++) {
                    int x = X[k] + i;
                    int y = Y[k] + j;

                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == 1) {
                        int v = x*n + y;
                        dsu.unionBySize(u, v);
                    }
                }
            }
            res.push_back(islands - dsu.getCount());
        }
        return res;
    }
};
