/*
Implement a trie with insert, search, and startsWith methods.
*/

/*
use array instead of vector
vector may cause memory overflow
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new Trie_node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie_node* cnt = head;
        for(int i = 0; i < word.length(); ++i)
        {
            if(!cnt->next[word[i]-'a'])
            {
                cnt->next[word[i]-'a'] = new Trie_node;
            }
            cnt = cnt->next[word[i]-'a'];
        }
        cnt->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie_node* cnt = head;
        for(int i = 0; i < word.length() && cnt!=NULL; ++i)
        {
            cnt = cnt->next[word[i]-'a'];
        }
        return cnt!=NULL && cnt->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie_node* cnt = head;
        for(int i = 0; i < prefix.length() && cnt!=NULL; ++i)
        {
            cnt = cnt->next[prefix[i]-'a'];
        }
        return cnt != NULL;
    }
private:
    struct Trie_node
    {
        bool is_word;
        Trie_node* next[26];
        Trie_node():is_word(false){memset(next, 0, sizeof(next));};
    };
    
    Trie_node* head;
    
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */