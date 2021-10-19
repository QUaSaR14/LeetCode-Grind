#include<bits/stdc++.h>
using namespace std;

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
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        DSU dsu(m*n);
        int ones = 0;
            
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    int u = i * n + j;
                    
                    grid[i][j] = '0';
                    
                    ones++;
                    for(int k=0; k<4; k++) {
                        int x = X[k] + i;
                        int y = Y[k] + j;

                        if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == '1') {
                            int v = x * n + y;
                    
                            dsu.unionBySize(u, v);
                    
                        }
                    }
                }
                
            }
        }
        
        return ones - dsu.getCount();
    }
};