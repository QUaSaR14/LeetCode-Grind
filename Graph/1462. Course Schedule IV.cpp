#include<bits/stdc++.h>
using namespace std;

/**
 * Approach 1 : using DFS
 * 
 * Idea here is to iterate over all nodes taking it as source, 
 * and find all reachable nodes from source. Mark all those nodes as reachable.
 * We use a matrix isPrerequisite[i][j] -> i come before j. Our task to fill this.
 * Traverse from source using DFS and mark all reachable nodes as true. (isPrerequisite[source][j])
 * Then we can simply query and return isPrerequisite[i][j].
*/
class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, vector<vector<bool>>& isPrerequisite, vector<bool>& vis, int source, int node) {
        vis[node] = true;
        isPrerequisite[source][node] = true;
        for(auto& adjNode : adj[node]) {
            if(!vis[adjNode]) {
                dfs(adj, isPrerequisite, vis, source, adjNode);
            }
        }
        
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        vector<vector<int>> adj(numCourses);
        
        for(auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            isPrerequisite[pre[0]][pre[1]] = true;
        }
        
        for(int i=0; i<numCourses; i++) {
            vector<bool> vis(numCourses, false);
            dfs(adj, isPrerequisite, vis, i, i);
        }
        
        vector<bool> res;
        for(auto& query : queries) {
            res.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return res;
    }
};

/**
 * Approach 2 : BFS (Topological Sort) 
 * Idea here is do simple topo sort. For reachable nodes, we can mark direct neighbours. But how we will mark indirect neighbours.
 * Logical Trick here for that is that, when we reach some "node", then we mark all its neighbours as reachable.
 * So, it we can reach say x -> y (directly or indirectly), and say z is neighbour of y. Then we can surely say x -> z always. 
 * This is because if we can reach y from some node x, then we can always reach z (neighbour of y) from x as well.
 * i.e if isPrerequisite[x][y] = true, and y->z (neighbour), then isPrerequisite[x][z] = true
 * Just this trick is sufficient and efficient to solve this problem.
*/

class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            isPrerequisite[pre[0]][pre[1]] = true;
            indegree[pre[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) if(indegree[i] == 0) q.push(i);
        
        while(q.size()) {
            int node = q.front(); q.pop();
            
            for(auto& adjnode : adj[node]) {
                for(int i=0; i<numCourses; i++) {
                    if(isPrerequisite[i][node]) isPrerequisite[i][adjnode] = true;
                }
                
                indegree[adjnode]--; 
                if(indegree[adjnode] == 0) q.push(adjnode);
            }
        }
    
        vector<bool> res;
        for(auto& query : queries) {
            res.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return res;
    }
};