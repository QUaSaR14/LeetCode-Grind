#include<bits/stdc++.h>
using namespace std;

static int X[4] = {-1, 0, 0, 1};
static int Y[4] = {0, -1, 1, 0};

class Solution {
public: 
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        int source = 0, destination = m*n - 1;
        priority_queue<pair<int, int>> pq;
        
        pq.push({A[0][0], source});
        int minVal = A[0][0];
        
        while(pq.size()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            int x = node/n, y = node%n;
            
            minVal = min(minVal, A[x][y]);
            if(node == destination) return minVal;
            
            A[x][y] = -1;
            
            for(int k=0; k<4; k++) {
                int i = x + X[k];
                int j = y + Y[k];
                
                if(i>=0 && j>=0 && i<m && j<n && A[i][j] != -1) {
                    pq.push({distance + A[i][j], i*n + j});
                }
            }
        }
        
        return minVal;
    }
};

/*
3 3
5 4 5
1 2 6
7 4 6

2 6
2 2 1 2 2 2
1 2 2 2 1 2

6 5
3 4 6 3 4
0 2 1 1 7
8 8 3 2 7
3 2 4 9 8
4 1 2 0 0
4 6 5 4 3
*/