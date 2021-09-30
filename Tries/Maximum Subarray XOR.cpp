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
            int bitVal = 1 - (bool)(num & (1<<bit));

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

    int maximumSubarrayXOR(vector<int> arr) {
        int n = arr.size();

        int prefixXOR = arr[0], maxXOR = arr[0];
        insert(prefixXOR);

        for(int i=0; i<n; i++) {
            prefixXOR = prefixXOR ^ arr[i];
            // Take the full, don't remove 
            // or Find how much we can remove
            maxXOR = max({maxXOR, prefixXOR, getMaxXOR(prefixXOR)});
            insert(prefixXOR);
        }
        return maxXOR;
    }
};