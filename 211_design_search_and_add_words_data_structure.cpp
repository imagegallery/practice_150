class Node{
    public:
        bool isWord;
        Node* children[26];
        Node(){
            isWord = false;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
        }
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int index = word[i] - 'a';
            if(node->children[index] == NULL){
                node->children[index] = new Node();
            }
            node = node->children[index];
        }
        node->isWord = true;
        
    }
    bool util_complexly_written(Node* &node, string word, int start){
        if(start == word.size()){
            if(node->isWord == true)
                return true;
            return false;
        }
        int index = word[start] - 'a';
        if(word[start] == '.'){
            for(int j = 0; j < 26; j++){
                if(node->children[j] != NULL){
                    if(util_complexly_written(node->children[j], word, start+1))
                        return true;
                }
            }
            return false;
        }else{
            if(node->children[index] == NULL){
                return false;
            }
            return util_complexly_written(node->children[index], word, start+1);
        }
    }
    bool util_nicely_written(Node* &node, string word, int start){
        if(node == NULL)
            return false;
        
        if(start == word.size()){
            return node->isWord;
        }

        if(word[start] != '.')
            return util_nicely_written(node->children[word[start] - 'a'], word, start + 1);
        else{
            for(int i = 0; i < 26; i++){
                if(util_nicely_written(node->children[i], word, start + 1))
                    return true;
            }
        }
        return false; 
    }
    bool search(string word) {
        Node* node = root;
        return util_nicely_written(node, word, 0);  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */