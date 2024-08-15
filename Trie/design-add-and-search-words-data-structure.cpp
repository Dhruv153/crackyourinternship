class TrieNode {
public:
    char value;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char value) {
        this->value = value;
        this->isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode('-'); }

    void insertWord(TrieNode* root, string word) {
        // Base Case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // 1 Case hum solve kar lenge
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* childNode;
        if (root->children[index] != NULL) {
            // Present hai -> to root ko aange traverse krdo
            childNode = root->children[index];
        } else {
            // Absent hai -> to ek new childNode create krke root ko aange
            // traverse krdo
            childNode = new TrieNode(ch);
            root->children[index] = childNode;
        }

        // Baki ka recursion solve kar lega
        insertWord(childNode, word.substr(1));
    }



    void addWord(string word) { insertWord(root, word); }




    bool searchWord(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // 1 case hum solve kar lenge
        char ch = word[0];

        if (ch == '.') {
            // Wildcard character, we need to check all possible paths
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL &&
                    searchWord(root->children[i], word.substr(1))) {
                    return true;
                }
            }
            return false;
        } else {
            int index = ch - 'a';
            TrieNode* childNode;

            if (root->children[index] != NULL) {
                // Present hai -> found means traverse kro
                childNode = root->children[index];
            } else {
                // absent hai -> not found means word hai nhi hai
                return false;
            }

            // ab recursion solve kar lega
            return searchWord(childNode, word.substr(1));
        }
    }

    bool search(string word) { return searchWord(root, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
