#include<bits/stdc++.h>
using namespace std;

static int X[4] = {-1,1,0,0};
static int Y[4] = {0,0,-1,1};

struct Node {
    Node* arr[26];
    string word = "";
    bool flag = false;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    
    bool isEnd() {
        return flag;
    }
    
    void setEnd(string& s) {
        flag = true;
        word = s;
    }
    
    string getWord() {
        return word;
    }
    
    void foundWord() {
        word = "";
        flag = false;
    }
};

class Solution {
public:
        
    void exist(vector<vector<char>>& board, Node* root, vector<string>& result, int i, int j, const int& n, const int& m) {
        if(board[i][j] == '#' || !root || !root->contains(board[i][j])) return;
        
        root = root->getNext(board[i][j]);
        
        if(root->isEnd()) {
            result.push_back(root->getWord());
            root->foundWord();
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        for(int k=0; k<4; k++) {
            int x = i + X[k];
            int y = j + Y[k];
            
            if(x>=0 && y>=0 && x<n && y<m && board[x][y] != '#') {
                exist(board, root, result, x, y, n, m);
            }
        }
        
        board[i][j] = temp;
    }
    
    vector<string> search(vector<vector<char>>& board, Node* root) {
        vector<string> result;
        
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] != '#' && root->contains(board[i][j])) {
                    exist(board, root, result, i, j, n, m);
                }
            }
        }
        return result;
    }
    
    void insert(Node* root, string& word) {
        for(auto& ch : word) {
            if(!root->contains(ch)) {
                root->put(ch, new Node());
            }
            root = root->getNext(ch);
        }
        root->setEnd(word);
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        
        // Build word Dictionary
        for(auto& word : words) {
            insert(root, word);
        }
        
        // Search for all words in the board
        return search(board, root);
    }
};