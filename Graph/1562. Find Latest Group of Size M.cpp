#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size, count;
public:
    
    DSU(int n) {
        count.resize(n+1, 0);
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
        
        // Decrement Current sizes of parU and parV
        // Since we are merging it
        count[size[parU]]--;
        count[size[parV]]--;
        
        if(size[parU] < size[parV]) {
            size[parV] += size[parU];
            parent[parU] = parV;
            
            // Increment count of new component formed
            count[size[parV]]++;
        }
        else {
            size[parU] += size[parV];
            parent[parV] = parU;
            
            // Increment count of new component formed
            count[size[parU]]++;
        }
    }
    
    int getCount(int m) {
        return count[m];
    }
    
    void incCount(int m) {
        count[m]++;
    }
    
};
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        
        DSU dsu(n);
        
        int lastStep = -1;
        int currStep = 1;
        
        string groups(n+1, '0');
        
        for(auto& i : arr) {
            
            groups[i] = '1';
            
            dsu.incCount(1);
            
            if(i-1 > 0 && groups[i-1] == '1') {
                dsu.unionBySize(i-1, i);
            }
            
            if(i+1 <= n && groups[i+1] == '1') {
                dsu.unionBySize(i, i+1);
            }
            
            if(dsu.getCount(m)) {
                lastStep = currStep;
            }
            
            currStep++;
        }
        
        return lastStep;
    }
};