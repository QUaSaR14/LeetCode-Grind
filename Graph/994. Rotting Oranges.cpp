#include<bit/stdc++.h>
using namespace std;

struct Node {
    int x, y, time;
    
    Node(int _x, int _y, int _time) {
        x = _x;
        y = _y;
        time = _time;
    }
};

static int X[4] = {-1,0,0,1};
static int Y[4] = {0,-1,1,0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<Node> q;
        int countOranges = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(grid[i][j] == 2) {
                    q.push(Node(i,j,0));
                }
                
                if(grid[i][j] != 0) {
                    countOranges++;    
                }
            }
        }
        
        int minTime = 0, count = 0;
        while(q.size()) {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            
            q.pop();
            
            count++;
            
            minTime = max(minTime, time);
            
            for(int k=0; k<4; k++) {
                int newX = x + X[k];
                int newY = y + Y[k];
                
                if(newX >=0 && newY >=0 && newX < n && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    q.push(Node(newX, newY, time+1));
                }
            }
        }
        
        return (count == countOranges) ? minTime : -1;
    }
};