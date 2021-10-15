#include<bits/stdc++.h>
using namespace std;

// Premium Question : DFS, String, Set 
// Problem link : https://leetcode.ca/all/694.html
// Solution Link : https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/dfs-and-bfs/694.-number-of-distinct-islands

/*
    Idea here is to do DFS and do similar traversal as we do in standard "Number of Islands" problem. 
    Trick here is to also store directions that we take, in form of a string for each island. 
    EX : "Up -> Left -> Up -> Right -> Down" as "ulurd" and store this string into a set.
    Thus, Number of Distinct islands will be simply size of this set in which we store strings.
*/

static int X[4] = {-1, 0, 1, 0};
static int Y[4] = {0, -1, 0, 1};
static char D[4] = {'u', 'l', 'd', 'r'};
class Solution {
public: 
    
    void dfs(vector<vector<int>>& grid, string& str, int x, int y, const int& m, const int& n, char ch) {
        
        grid[x][y] = 0;
        
        str.push_back(ch);
        
        for(int k=0; k<4; k++) {
            int i = X[k] + x;
            int j = Y[k] + y;
            
            if(i>=0 && j>=0 && i<m && j<n && grid[i][j]) {
                dfs(grid, str, i, j, m, n, D[k]);
            }
        }       
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        unordered_set<string> st;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    string s = "";
                    dfs(grid, s, i, j, m, n, 'c'); 
                    cout << s << endl;
                    st.insert(s);   
                }
            }
        }
        
        return st.size();
    }
};
