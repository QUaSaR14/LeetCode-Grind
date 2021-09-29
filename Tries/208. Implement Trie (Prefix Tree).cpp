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
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root; 
        for(int i = 0; i < word.size(); i++) {
            if(!temp->contains(word[i])) {
                Node* newNode = new Node(); 
                temp->put(word[i], newNode); 
            }
            temp = temp->getNext(word[i]); 
        }
        temp->setFlag(); 
    }
    
    bool search(string word) {
        Node* temp = root; 
        for(int i = 0; i< word.size(); i++) {
            if(temp->contains(word[i])) {
                temp = temp->getNext(word[i]); 
            }
            else {
                return false; 
            }
        }
        return temp->isFlagSet(); 
    }
    
    bool startsWith(string prefix) {
        Node* temp = root; 
        for(int i = 0; i < prefix.size(); i++) {
            if(temp->contains(prefix[i])) {
                temp = temp->getNext(prefix[i]); 
            }
            else {
                return false; 
            }
        }
        return true; 
    }
};