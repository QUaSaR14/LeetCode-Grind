#include<bits/stdc++.h>
using namespace std;

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
        
        if(size[parU] < size[parV]) {
            size[parV] += size[parU];
            parent[parU] = parV;
        }
        else {
            size[parU] += size[parV];
            parent[parV] = parU;
        }
    }
    
    void reset(int node) {
        parent[node] = node;
    }
};

class Solution {
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        DSU dsu(n);
            
        dsu.unionBySize(0, firstPerson);
        
        sort(meetings.begin(), meetings.end(), compare);
        
        int i = 0, len = meetings.size();
        for(int i=0; i<len; ) {

            int j = i;
            vector<int> ppl;
            while(j+1 < len && meetings[j][2] == meetings[j+1][2]) {
                
                int u = meetings[j][0], v = meetings[j][1];
                dsu.unionBySize(u, v);
                ppl.push_back(u);
                ppl.push_back(v);
                
                j++;
            }
            
            int u = meetings[j][0], v = meetings[j][1];
            dsu.unionBySize(u, v);
            
            ppl.push_back(u);
            ppl.push_back(v);
            
            i = j+1;
            
            for(auto& it : ppl) {
                if(dsu.findParent(it) != dsu.findParent(0)) {
                    dsu.reset(it);
                }
                else {
                    st.insert(it);
                }
            }
        }
        
        return vector<int>(st.begin(), st.end());
    }
};