#include<bits/stdc++.h>
using namespace std;

// Premium Question : DSU, String, Map
// Problem Link : https://leetcode.ca/all/737.html
// Solution Link : https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/graph/737.-sentence-similarity-ii

/*
    Idea here is first map all the words in pairs array to a unique id (integer). This will help in lookups.
    Now, simply do union find for every pair. 
    Ex: {great, good} , {fine, good} , {acting, drama} , {skills, talent}
    great -> 1 , good -> 2, fine -> 3, acting -> 4, drama -> 5, skills -> 6, talent -> 7
    Then union all pairs i.e union(1, 2), union(3, 1), etc.

    Now, that we have grouped all pairs in DSU, we can iterate over words1 and words2. There are 2 cases : 
        1. If word1[i] == word2[i], they are similar.
        2. If word1[i] != word2[i], then we check if both words belong to same component or not. 
            i.e if both have same parent or not. If yes then continue. Else return false.
    
    In the end if words of both lists are same, then return true. 

    Time : O(P + W * 4a) , P : No. of pairs to do union. , W : No. of words and to do find operation in DSU
    Space : O(P) , to store all pairs in map and to create parent & rank for DSU
*/

class DSU {
    vector<int> parent, size;
public: 
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
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
    }
};
class Solution {
public: 
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs){
        
        if(words1.size() != words2.size()) return false;
        
        unordered_map<string, int> getId;
        
        DSU dsu(2 * pairs.size());
        
        int counter = 0;
        for(auto& pair : pairs) {
            int u,v;
            if(getId.find(pair[0]) == getId.end()) {
                getId[pair[0]] = u = counter++;
            }
            else {
                u = getId[pair[0]];
            }
            
            if(getId.find(pair[1]) == getId.end()) {
                getId[pair[1]] = v = counter++;
            }
            else {
                v = getId[pair[1]];
            }
            
            dsu.unionBySize(u, v);
        }
        
        for(int i=0; i<words1.size(); i++) {
            if(words1[i] == words2[i]) continue;
            else {
                if(getId.find(words1[i]) == getId.end()) return false;
                if(getId.find(words2[i]) == getId.end()) return false;
                
                int words1_id = getId[words1[i]];
                int words2_id = getId[words2[i]];
                
                if(dsu.findParent(words1_id) != dsu.findParent(words2_id)) return false;
            }
        }
        
        return true;
    }
};
/*
3 4
treat fight miss
like train lost
treat catch
train fight
like catch
miss lost

3 4
great acting skills
fine drama talent
great good
fine good 
acting drama
skills talent

3 5
i like naruto
i love pepcoding
anime naruto
edtech pepcoding
anime pepcoding
like hate
hate anime
*/