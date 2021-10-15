#include<bit/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
    int maxComponentSize;
public :
    
    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        maxComponentSize = 1;
    }
    
    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    void unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(parU == parV) return;
        
        if(size[parU] <= size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
            maxComponentSize = max(maxComponentSize, size[parV]);
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
            maxComponentSize = max(maxComponentSize, size[parU]);
        }
    }
    
    int getMaxComponent() {
        return maxComponentSize;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        
        DSU dsu(n);
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            if(mp.find(nums[i]) != mp.end()) continue;
            
            if(mp.find(nums[i]-1) != mp.end()) dsu.unionBySize(i, mp[nums[i]-1]);
            if(mp.find(nums[i]+1) != mp.end()) dsu.unionBySize(i, mp[nums[i]+1]);
            
            mp[nums[i]] = i;
        }
        
        return dsu.getMaxComponent();
    }
};