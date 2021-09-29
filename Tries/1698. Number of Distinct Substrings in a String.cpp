#include<bits.stdc++.h>
using namespace std;

struct Node {
	Node* arr[26]; 
	bool flag = false; 
 
	bool contains(char c) {
		return (arr[c - 'a'] != NULL); 
	}
 
	void put(char c, Node* newNode) {
		arr[c - 'a'] = newNode; 
	}
 
	Node* getNext(char ch) {
		return arr[ch - 'a']; 
	}
 
	void setFlag() {
		flag = true; 
	}
 
	bool isFlagSet() {
		return flag; 
	}
};

class Solution {
public:
    
    int distinctSubstrings(string s) {

        int n = s.size();
        Node* root = new Node();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            Node* temp = root;
            for(int j=0; j<n; j++) {

                if(!(temp->contains(s[j]))) {
                    Node* newNode = new Node();
                    temp->put(s[j], newNode);
                    temp->setFlag();
                    cnt++;
                }
                temp = temp->getNext(s[j]);
            }
        }
        return cnt;
    }
    
}