#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* arr[26];
    bool isEnd = false;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    
    void setEnd() {
        isEnd = true;
    }
    
    bool getEnd() {
        return isEnd;
    }
    
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(auto& ch : word) {
            if(!temp->contains(ch)) {
                temp->put(ch, new Node());
            }
            temp = temp->getNext(ch);
        }
        temp->setEnd();
    }
    
    bool check(Node* node, string& word, int idx=0) {
        if(!node) return false;
        if(idx == word.size()) return node->getEnd();
        
        if(word[idx] == '.') {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if(!node->contains(ch)) continue;
                if(check(node->getNext(ch), word, idx+1)) return true;
            }
        }
        else if(node->contains(word[idx])) {
             return check(node->getNext(word[idx]), word, idx+1);
        }
        
        return false;
    }
    
    bool search(string word) {
        return check(root, word);
    }
};