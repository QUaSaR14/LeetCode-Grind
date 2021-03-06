#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* arr[2];
    int count = 0;   // Count of number of elements till current node (same prefix)
    int val;            
    
    void put(int bitNo, Node* newNode) {
        arr[bitNo] = newNode;
    }
    
    bool contains(int bitNo) {
        return arr[bitNo] != NULL;
    }
    
    Node* getNext(int bitNo) {
        return arr[bitNo];
    }
    
    void setCount(int bitVal, int d) { 
        arr[bitVal]->count += d;  // Here if d>0 means insert element, and d<0 means remove element
    }
    
    int getCount(int bitVal) {
        return arr[bitVal]->count;
    }
};

class Solution {
public:
    
    Node* root = new Node();
    
    void update(int num, int d) {
        Node* temp = root;
        for(int bit = 18; bit>=0; bit--) {
            int bitVal = (bool)(num & (1<<bit));
            
            if(!temp->contains(bitVal)) {
                temp->put(bitVal, new Node());
            }
            temp->setCount(bitVal, d);
            temp = temp->getNext(bitVal);
        }        
        temp->val = num;
    }
    
    int getMaxXOR(int num) {
        Node* temp = root;
        for(int bit=18; bit>=0; bit--) {
            int bitVal = !(bool)(num & (1<<bit));
            if(temp->contains(bitVal) && temp->getCount(bitVal)) {
                temp = temp->getNext(bitVal);
            }
            else if(temp->contains(1-bitVal)) {
                temp = temp->getNext(1-bitVal);
            }
        }
        return num ^ (temp->val);
    }
    
    void traverse(vector<vector<int>>& adj, unordered_map<int, vector<pair<int, int>>>& queries, vector<int>& ans, int node) {
        
        // Insert node into trie
        update(node, 1);
        
        // Find Maximum XOR for each query with given node
        for(auto& i : queries[node]) {
            ans[i.second] = getMaxXOR(i.first);
        }
        
        // Preorder Traversal 
        for(auto& v : adj[node]) {
            traverse(adj, queries, ans, v);
        }
        
        // Remove node from trie
        update(node, -1);
    }
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        
        int n = parents.size();
        int m = queries.size();
        vector<vector<int>> adj(n);  // Make it as a graph on which we can do Preorder Traversal
        int start = 0;
        for(int i=0; i<n; i++) { 
            if(parents[i] == -1) start = i;
            else adj[parents[i]].push_back(i);
        }
        
        // Store queries in modified format. 
        // So that we can easily access the node from start node -> root path
        // newQueries[node(i)] = {val(i), i} 
        unordered_map<int, vector<pair<int, int>>> newQueries;
        for(int i=0; i<m; i++) {
            newQueries[queries[i][0]].push_back({queries[i][1], i});
        }
        
        vector<int> ans(m); // Store the result of all queries
        traverse(adj, newQueries, ans, start); // Preorder traversal on Tree
        return ans;
    }
};