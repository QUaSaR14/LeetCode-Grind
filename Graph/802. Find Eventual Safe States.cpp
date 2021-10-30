#include<bits/stdc++.h>
using namespace std;

/**
 * Approach 1 : using BFS (Topo Sort)
 * 
 * Trick here is to reverse direction of all edges. And then perform simple topo sort.
 * Reversing edges will help us in classifying TERMINAL NODES => indegree is zero
 * Also, doing topo sort will exclude all nodes that are present in a cyclic path.  
 * So, topo sort will give us the all nodes that are either terminal or there is a path to terminal nodes.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        int i = 0;
        for(auto& g : graph) {
            for(auto& it : g) {
                adj[it].push_back(i);
                indegree[i]++;
            }
            i++;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> safeNodes;
        
        while(q.size()) {
            int node = q.front(); q.pop();
            
            safeNodes.push_back(node);
            
            for(auto& adjnode : adj[node]) {
                if(--indegree[adjnode] == 0) q.push(adjnode);
            }
        }
    
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};

/**
 * Approach 2: DFS (Detect Cycle)
*/

class Solution {
public:
    
    bool detectCycle(vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& isSafe, int node) {
        
        vis[node] = true;
        
        for(auto& adjnode : graph[node]) {
            if(!vis[adjnode]) {
                if(detectCycle(graph, vis, isSafe, adjnode)) 
                    return true;
            }
            else if(!isSafe[adjnode]) return true;
        }
        
        isSafe[node] = true;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<bool> vis(n, false);
        vector<bool> isSafe(n, false);
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                detectCycle(graph, vis, isSafe, i);
            }
        }
        
        vector<int> safeNodes;
        for(int i=0; i<n; i++) {
            if(isSafe[i]) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};

/**
 * Apprach 3: DFS using states to detect cycle
 * 
 * In normal (standard) cycle detection using DFS we use two visited array, one to check overall visited and one to check visited for a path.
 * So Idea, here we use a single array of int, which store the state of a node. 
 * Here we mark node as unsafe : if node is part of cycle. Otherwise we mark it as safe. 
 * Unsafe is when a node is already visited overall as well in dfs path.
 * Thus, all nodes that are not present in a cycle are Safe nodes and we return those nodes in sorted order.
*/

class Solution {
public:
    
    /*
        State of Nodes : 
            
            0 -> Unvisited
            1 -> Visited
            2 -> Safe
            3 -> Unsafe (Part of a cycle)
    */
    
    bool detectCycle(vector<vector<int>>& graph, vector<int>& state, int node) {
        
        state[node] = 1;
        
        for(auto& adjnode : graph[node]) {
            // If node is unvisited, then continue traversal
            if(state[adjnode] == 0) {
                if(detectCycle(graph, state, adjnode)) {
                    state[node] = 3;
                    return true;
                }
            }
            else if(state[adjnode] != 2) {
                state[node] = 3;
                return true;
            }
        }
        
        state[node] = 2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> state(n, 0);
        
        for(int i=0; i<n; i++) {
            if(state[i] == 0) {
                detectCycle(graph, state, i);
            }
        }
        
        vector<int> safeNodes;
        
        for(int i=0; i<n; i++) {
            if(state[i] == 2) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};