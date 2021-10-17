#include<bits/stdc++.h>
using namespace std;

// Premium Question : DSU, String
// Problem Link : https://leetcode.ca/all/1061.html
// Solution Link :  https://walkccc.me/LeetCode/problems/1061/

/*
    Idea is to first union all equivalent chars of string A and B. Instead of doing union by size, we perform union by smallest number. 
    i.e. if parentU < parentV , then parent with smaller values becomes parent. 
    This simple change will always give us the smallest parent value. And finally will help us to get Lexi. Smallest Eq. String.
    Basically, parent of each group will have smallest value among all values.

    Ex: group : {1, 4, 3, 2, 5} , then ultimate parent of this group will be 1 since it has smallest value. 

    To get Lexi. Smallest Eq. string of S, we will simply find parent of each character, and add to result. 
    Parent will always have smallest value possible among its group. 
*/

class DSU {
    vector<int> parent;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
        }
    }
    
    int findParent(int num) {
        if(parent[num] == num) return num;
        return parent[num] = findParent(parent[num]);
    }
    
    void unionByValue(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) {
            return;
        }
        
        if(parU < parV) {
            parent[parV] = parU;
        }
        else {
            parent[parU] = parV;
        }
    }
};

class Solution {
public: 
    string smallestEquivalentString(string& A, string& B, string& S) {
        
        DSU dsu(26);
        int n = A.size();
        for(int i=0; i<n; i++) {
            dsu.unionByValue(A[i]-'a', B[i]-'a');
        }
        
        string res = "";
        for(auto& ch : S) {
            res += dsu.findParent(ch-'a')+'a';
        }
        return res;
    } 
};

/*
parker
morris
parser

hello 
world
hold

leetcode
programs
sourcecode
*/