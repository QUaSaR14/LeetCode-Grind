#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* arr[26];
    bool flag = false;
    int idx = -1;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    
    Node* getNext(char ch) {
        return arr[ch-'a'] ;
    }
    
    void setEnd(int index) {
        flag = true;
        idx = index;
    }
    
    bool getEnd() {
        return flag;
    }
};


class Solution {
public:
    
    void insert(Node* root, string& s, int index) {
        for(auto& ch : s) {
            if(!root->contains(ch)) {
                root->put(ch, new Node());
            }
            root = root->getNext(ch);
        }
        root->setEnd(index);
    }
    
    void buildDictionary(Node* root, vector<string>& dictionary) { 
        int idx = 0;
        for(auto& word : dictionary) {
            insert(root, word, idx);
            idx++;
        }
    }
    
    int search(Node* root, string& s) {
        for(auto& ch : s) {
            if(!root || !root->contains(ch)) return -1;
            root = root->getNext(ch);
            if(root->getEnd()) return root->idx;
        }
        return -1;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* root = new Node();
        
        buildDictionary(root, dictionary);
        
        int n = sentence.size(), i = 0;
        string replacedSentence = "";
        while(i < n) {
            string word = "";
            int j = i;
            while(j < n && sentence[j] != ' ') {
                word += sentence[j++];
            }
            i = j+1;
            
            int idx = search(root, word);
            
            replacedSentence += (idx != -1) ? dictionary[idx] : word;
            replacedSentence += " ";
        }
        
        replacedSentence.pop_back();
        return replacedSentence;
    }
};