#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* arr[2];
    int value;
    bool contains(int bitNo) {
        return arr[bitNo] != NULL;
    }

    void put(int bitNo, Node* newNode) {
        arr[bitNo] = newNode;
    }

    Node* getNext(int bitNo) {
        return arr[bitNo];
    }
};

class Solution {
public :
    Node* root = new Node();

    void insert(int num) {
        Node* temp = root;
        for(int bit=31; bit>=0; bit--) {
            int bitVal = num & (1<<bit);
            if(temp->contains(bitVal)) {
                temp = temp->getNext(bitVal);
            }
            else {
                temp->put(bitVal, new Node());
                temp = temp->getNext(bitVal);
            }
        }
        temp->value = num;
    }

    int getMinXOR(int num) {
        Node* temp = root;
        for(int bit=31; bit>=0; bit--) {
            int bitVal = num & (1<<bit);
            // If we find same bit number then move ahead
            // Otherwise pick the one that is present
            if(temp->contains(bitVal)) {
                temp = temp->getNext(bitVal);
            }
            else if (!temp->contains(bitVal)) {
                temp = temp->getNext(1 - bitVal);
            }
            else {
                return 0;
            }
        }
        return num ^ (temp->value);
    }

    int findMinimumXOR(vector<int> arr) {
        int n = arr.size();
        int minXOR = arr[0] ^ arr[1];
        insert(arr[0]);
        for(int i=1; i<n; i++) {
            minXOR = min(minXOR, getMinXOR(arr[i]));
            insert(arr[i]);
        }
        return minXOR;
    }
};