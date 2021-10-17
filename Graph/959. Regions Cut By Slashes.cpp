#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
    int count;
    int cycles;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        count = n;
        cycles = 0;
    }
    
    int findParent(int num) {
        if(parent[num] == num) return num;
        return parent[num] = findParent(parent[num]);
    }
    
    void unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) {
            cycles++;
            return;
        }
        
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
    
    int getSize(int n) {
        return size[n];
    }
    
    int getCycles() {
        return cycles;
    }
};
class Solution {
public:
    
    /* 
        '/' -> (i+1, j) (i, j+1)
        '\' -> (i, j) (i+1, j+1)
    
    */
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();
        
        n++;
        DSU dsu(n*n);
        
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-1; j++) {
                if(grid[i][j] != ' ') {
                    pair<int, int> start, end;
                    
                    if(grid[i][j] == '/') {
                        start = {i, j+1};
                        end = {i+1, j};
                    }
                    else {
                        start = {i,j};
                        end = {i+1, j+1};
                    }
                    
                    int u = (start.first*n) + start.second;
                    int v = (end.first*n) + end.second;

                    dsu.unionBySize(u, v);
                }
            }
        }
        
        // TOP and BOTTOM rows
        for(int j=0; j<n-1; j++) {
            
            // TOP
            int i = 0;
            int u = i*n + j;

            dsu.unionBySize(u, u+1);
            
            // BOTTOM
            i = n-1;
            u = i*n + j;

            dsu.unionBySize(u, u+1);        
        }
        
        // LEFT and RIGHT columns
        for(int i=0; i<n-1; i++) {
            
            // TOP
            int j = 0;
            int u = i*n + j;

            dsu.unionBySize(u, u+n);
            
            // BOTTOM
            j = n-1;
            u = i*n + j;

            dsu.unionBySize(u, u+n);        
        }
        
        return dsu.getCycles();
    }
};

/*
Sample TC: 

/ / /
/   \
    /

*/