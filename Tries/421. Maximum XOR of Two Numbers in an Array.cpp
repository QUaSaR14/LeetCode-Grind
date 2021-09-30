#include<bits/stdc++.h>
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

class Solution {
public:
    Node* root = new Node();
    
    void insert(int num) {
        Node* temp = root;
        for(int bit = 31; bit>=0; bit--) {
            int bitVal = (bool)(num & (1<<bit));
            if(temp->contains(bitVal)) {
                temp = temp->getNext(bitVal);
            } 
            else {
                temp->put(bitVal, new Node());
                temp = temp->getNext(bitVal);
            }
        }
        temp->val = num;
    }
    
    int getMaxXOR(int num) {
        Node* temp = root;
        for(int bit=31; bit>=0; bit--) {
            int bitVal = !(bool)(num & (1<<bit));
            if(temp->contains(bitVal)) {
                temp = temp->getNext(bitVal);
            }
            else if(temp->contains(1-bitVal)) {
                temp = temp->getNext(1-bitVal);
            }
            else return 0;
        }
        return num ^ (temp->val);
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(); 
        
        if(n == 1) return 0;
        if(n == 2) return nums[0] ^ nums[1];
        
        int maxXOR = nums[0] ^ nums[1];
        insert(nums[0]);
        for(int i=1; i<n; i++) {
            maxXOR = max(maxXOR, getMaxXOR(nums[i]));
            insert(nums[i]);
        }
        return maxXOR;
    }
};