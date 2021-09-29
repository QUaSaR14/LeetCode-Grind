struct Node {
  
    Node* arr[26];
    bool flag = false;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
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
    Node* root = new Node();
    
    int insert(string word) {
        Node* temp = root;
        int cnt = 0;    
        for(auto& ch : word)
        {
            if(! temp->contains(ch)) {
                Node* newNode = new Node();
                temp->put(ch, newNode);
            }
            
            if(temp->isFlagSet()) cnt++;
            temp = temp->getNext(ch);
        }
        temp->setFlag();
        return cnt;
    }
    
    string longestWord(vector<string>& words) {
        
        sort(words.begin(), words.end());
        string res = "";
        
        for(int i=0; i<words.size(); i++) {
            int count = insert(words[i]);
            
            if(count + 1 == words[i].size() && count + 1 > res.size()) {
                res = words[i];
            }
        }
        return res;
    }
};