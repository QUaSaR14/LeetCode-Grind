#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* arr[26];
    vector<int> suggestions;
    int size = 0;
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    
    void putSuggestions(char ch, int idx) {
        if(arr[ch-'a']->size < 3)
        {
            arr[ch-'a']->suggestions.push_back(idx);
            arr[ch-'a']->size++;
        }
    }
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    
    vector<int> getSuggestions(char ch) {
        return arr[ch-'a']->suggestions;
    }
};

class Solution {
public:
    
    Node* root = new Node();
    
    vector<vector<string>> res;
    
    void insert(string s, int idx) {
        Node* temp = root;
        
        for(auto& ch : s) {
            if(!temp->contains(ch)) {
                temp->put(ch, new Node());
            }
            temp->putSuggestions(ch, idx);
            temp = temp->getNext(ch);
        }
    }
    
    void startWith(vector<string>& products, string s) {
        Node* temp = root;
        for(auto& ch : s) {
            vector<string> ans;
            if(temp)
            {
                if(temp->contains(ch)) {
                    for(auto& i : temp->getSuggestions(ch)) {
                        ans.push_back(products[i]);
                    }
                }
                temp = temp->getNext(ch);
            }
            res.push_back(ans);
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        int i=0;
        for(auto& product : products) {
            insert(product, i);
            i++;
        }
        
        startWith(products, searchWord);
        
        return res;
    }
};