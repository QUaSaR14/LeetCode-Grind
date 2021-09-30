#include<bit/stdc++.h>
using namespace std;

struct Node {
    Node* arr[2];
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
};

static bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    
    Node* root = new Node();
    
    void insert(int num) {
        Node* temp = root;
        
        for(int bit = 31; bit >= 0; bit--) {
            int bitVal = (bool)(num & (1<<bit)); // Get the bit value of ith bit
            
            if(!temp->contains(bitVal)) {
                temp->put(bitVal, new Node());
            }
            temp = temp->getNext(bitVal);
        }
        temp->val = num;
    }
    
    int getMaxXOR(int num) { 
        Node* temp = root;
        
        for(int bit = 31; bit >= 0; bit--) {
            int bitVal = (bool)(num & (1<<bit)); // Get the bit value of ith bit
            
            if(temp->contains(1-bitVal)) {
                temp = temp->getNext(1-bitVal);
            }
            else if(temp->contains(bitVal)) {
                temp = temp->getNext(bitVal);
            }
            else return -1;
        }
        return num ^ temp->val;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<vector<int>> copyQueries = queries;
        int n = queries.size();
        
        for(int i=0; i<n; i++) {
            copyQueries[i].push_back(i);
        }
        
        sort(nums.begin(), nums.end());
        sort(copyQueries.begin(), copyQueries.end(), compare);
        
        vector<int> ans(n, 0);
        
        int i = 0, m = nums.size();
        for(auto& query : copyQueries) {
            int num = query[0];
            int limit = query[1];
            int idx = query[2];
            while(i < m && nums[i] <= limit) {
                insert(nums[i]);
                i++;
            }
            ans[idx] = getMaxXOR(num);
        }
        return ans;
    }
};




















